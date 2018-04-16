/*
** algo_breadth.c for breadth in /home/sachs_a/delivery/IA/dante/breadth/src/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Apr 24 14:29:45 2017 Alexandre Sachs
** Last update Feb Apr 24 18:49:13 2017
*/

#include <unistd.h>
#include <stdio.h>
#include "basics.h"

#include <string.h>
#include "breadth.h"


int	intlen(int *line)
{
  int	i;

  i = 0;
  while (line[i] != -3)
    i++;
  return (i);
}

int	update_position(int **maze, int size, int *pos, int val)
{
  if (pos[0] - 1 >= 0 && maze[pos[0] - 1][pos[1]] == val - 1)
    pos[0] -= 1;
  else if (pos[1] - 1 >= 0 && maze[pos[0]][pos[1] - 1] == val - 1)
    pos[1] -= 1;
  else if (pos[0] + 1 < size && maze[pos[0] + 1][pos[1]] == val - 1)
    pos[0] += 1;
  else
    pos[1] += 1;
  maze[pos[0]][pos[1]] = 0;
  return (0);
}

int	find_way(int **maze, int size, int *pos)
{
  int	val;

  pos[0] -= 1;
  pos[1] -= 1;
  val = maze[size - 1][intlen(maze[size - 2]) - 1];
  if (val == -2)
    {
      printf("Sorry, this map has no solution\n");
      return (84);
    }
  maze[pos[0]][pos[1]] = 0;
  while (val != 0)
    {
      update_position(maze, size, pos, val);
      val--;
    }
  return (0);
}

int	update_adjacents(int **maze, int *pos, int size, int val)
{
  int	i;

  i = 0;
  if (pos[0] - 1 >= 0 && maze[pos[0] - 1][pos[1]] == -1)
    {
      maze[pos[0] - 1][pos[1]] = val + 1;
      i = 1;
    }
  if (pos[0] + 1 < size && maze[pos[0] + 1][pos[1]] == -1)
    {
      maze[pos[0] + 1][pos[1]] = val + 1;
      i = 1;
    }
  if (pos[1] - 1 >= 0 && maze[pos[0]][pos[1] - 1] == -1)
    {
      maze[pos[0]][pos[1] - 1] = val + 1;
      i = 1;
    }
  if (pos[1] + 1 < size && maze[pos[0]][pos[1] + 1] == -1)
    {
      maze[pos[0]][pos[1] + 1] = val + 1;
      i = 1;
    }
  return (i);
}

int	algo_breadth(int **maze, int *pos, int size)
{
  int	val;

  val = 0;
  maze[0][0] = 0;
  while (maze[size - 1][intlen(maze[size - 2]) - 1] == -1)
    {
      pos[0] = 0;
      while (pos[0] < size)
	{
	  pos[1] = 0;
	  while (maze[pos[0]][pos[1]] != -3)
	    {
	      if (maze[pos[0]][pos[1]] == val)
		if (!update_adjacents(maze, pos, size, val))
		  return (printf("Sorry, this map has no solution.\n"), 84);
	      pos[1]++;
	    }
	  pos[0]++;
	}
      val++;
    }
  return (0);
}
