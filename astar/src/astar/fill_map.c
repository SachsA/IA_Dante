/*
** fill_map.c for fill_map in /home/sachs_a/delivery/IA/dante/astar/src/astar
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Apr 28 16:05:08 2017 Alexandre Sachs
** Last update Fri Apr 28 16:05:08 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "astar.h"

int	calc_heuris(t_pos *size, int i, int j)
{
  int	val;

  val = 0;
  while (i + 1 < size->y)
    {
      val++;
      i++;
    }
  while (j + 1 < size->x)
    {
      val++;
      j++;
    }
  return (val);
}

int	heuris(t_maze ***maze, t_pos *size)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size->y)
    {
      j = -1;
      while (++j < size->x)
	{
	  if ((*maze)[i][j].h == -1)
	    (*maze)[i][j].h = calc_heuris(size, i, j) * 10;
	  else
	    (*maze)[i][j].h = -2;
	}
    }
  return (0);
}

int	fill_map(t_maze **line, char *str)
{
  int	i;

  i = 0;
  if ((*line = malloc(sizeof(t_maze) * (strlen(str) + 1))) == NULL)
    return (84);
  while (str[i] != '\0')
    {
      if (str[i] == 'X')
	{
	  (*line)[i].h = -2;
	  (*line)[i].g = -2;
	  (*line)[i].f = -2;
	}
      else
	{
	  (*line)[i].h = -1;
	  (*line)[i].g = -1;
	  (*line)[i].f = -1;
	}
      i++;
    }
  return (0);
}
