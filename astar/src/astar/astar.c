/*
** astar.c for astar in /home/sachs_a/delivery/IA/dante/astar/src/astar
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Apr 28 15:58:05 2017 Alexandre Sachs
** Last update May May 11 15:00:56 2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "astar.h"
#include "basics.h"
#include "get_next_line.h"

int		astar(int fd)
{
  int		i;
  char		*str;
  t_pos		size;
  t_maze	**maze;

  get_size(fd, &size);
  if ((maze = malloc(sizeof(t_maze *) * (size.y + 1))) == NULL)
    return (84);
  maze[size.y] = NULL;
  lseek(fd, 0, SEEK_SET);
  i = 0;
  while ((str = get_next_line(fd)))
    {
      if ((check_line(str) == 84) || fill_map(&(maze[i]), str) == 84)
	return (free_astar(str, maze), 84);
      free(str);
      i++;
    }
  heuris(&maze, &size);
  if (algo_astar(maze, &size) == 84)
    return (84);
  find_way(maze, &size);
  my_show_wordtab_end(maze, &size);
  return (free_astar(str, maze), 0);
}
