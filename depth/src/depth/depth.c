/*
** depth.c for depth in /home/sachs_a/delivery/IA/dante/depth/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Apr 21 19:12:37 2017 Alexandre Sachs
** Last update Fri Apr 21 19:12:37 2017 Alexandre Sachs
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "depth.h"
#include "basics.h"
#include "get_next_line.h"

int	depth(int fd)
{
  int	i;
  int	size;
  int	pos[2];
  char	**maze;
  char	*str;

  i = 0;
  pos[0] = 0;
  pos[1] = 0;
  size = get_size(fd);
  if ((maze = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (84);
  maze[size] = NULL;
  lseek(fd, 0, SEEK_SET);
  while ((str = get_next_line(fd)))
    {
      if ((check_line(str) == 84) || ((maze[i] = strdup(str)) == NULL))
	return (free_depth(str, maze), 84);
      free(str);
      i++;
    }
  maze[0][0] = 'o';
  algo_depth2(maze, pos, size);
  my_show_wordtab(maze);
  return (free_depth(str, maze), 0);
}
