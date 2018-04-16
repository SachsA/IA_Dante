/*
** main.c for Dante in /home/invicta/dante/generator/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Fri Apr 14 11:09:00 2017 Kellian CIPIERRE
** Last update Mar Apr 18 11:19:29 2017
*/

#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "generator.h"

int		maze_creator(t_maze *maze)
{
  t_pos		pos;
  FILE		*file;

  file = fopen("maze.txt", "w+");
  pos.y = 0;
  while (pos.y < maze->height)
    {
      pos.x = 0;
      while (pos.x < maze->width)
	{
	  printf("%c", maze->maze[pos.y][pos.x]);
	  fprintf(file , "%c", maze->maze[pos.y][pos.x]);
	  pos.x++;
	}
      if (pos.y < maze->height - 1)
	fprintf(file, "\n");
      printf("\n");
      pos.y++;
    }
  fclose(file);
  return (0);
}

int		maze_free(t_maze *maze)
{
  int		i;

  i = 0;
  while (i < maze->height)
    free(maze->maze[i++]);
  free(maze->maze);
  return (0);
}

int		main(int ac, char **av)
{
  t_maze	maze;
  int		opt;

  if (ac != 3 && ac != 4)
    return (84);
  maze.height = atoi(av[1]);
  maze.width = atoi(av[2]);
  maze.maze = NULL;
  opt = 1;
  if (ac == 4 && strcmp(av[3], "perfect") == 0)
      opt = 0;
  if ((maze_init(&maze)) == -1)
    return (84);
  maze_generator(&maze, opt);
  maze_creator(&maze);
  maze_free(&maze);
  return (0);
}
