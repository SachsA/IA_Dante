/*
** breadth.c for breadth in /home/sachs_a/delivery/IA/dante/breadth/src/breadth
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Apr 24 14:30:18 2017 Alexandre Sachs
** Last update Feb Apr 24 18:16:40 2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "basics.h"
#include "breadth.h"
#include "get_next_line.h"

int	fill_map(int **line, char *str)
{
  int	i;

  i = 0;
  if ((*line = malloc(sizeof(int) * (strlen(str) + 1))) == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == 'X')
	(*line)[i] = -2;
      else
	(*line)[i] = -1;
      i++;
    }
  (*line)[i] = -3;
  return (0);
}

int	breadth(int fd)
{
  int	i;
  int	size;
  int	pos[2];
  int	**maze;
  char	*str;

  pos[0] = 0;
  pos[1] = 0;
  size = get_size(fd);
  if ((maze = malloc(sizeof(int *) * (size + 1))) == NULL)
    return (84);
  maze[size] = NULL;
  lseek(fd, 0, SEEK_SET);
  i = 0;
  while ((str = get_next_line(fd)))
    {
      if ((check_line(str) == 84) || fill_map(&(maze[i]), str))
	return (free_breadth(str, maze), 84);
      free(str);
      i++;
    }
  if (algo_breadth(maze, pos, size) != 84 && find_way(maze, size, pos) != 84)
    my_show_wordtab(maze);
  return (free_breadth(str, maze), 0);
}
