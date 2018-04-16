/*
** algo_depth.c for algo_depth in /home/sachs_a/delivery/IA/dante/depth/src/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 12:46:08 2017 Alexandre Sachs
** Last update Sun Apr 23 12:46:08 2017 Alexandre Sachs
*/

#include <string.h>
#include "depth.h"

int	algo_depth1(char **maze, int *pos, int size)
{
  if (move_down(maze, pos, size) == 0)
    {
      pos[0] += 1;
      maze[pos[0]][pos[1]] = 'o';
      if (algo_depth2(maze, pos, size))
	return (1);
      pos[0] -= 1;
    }
  if (move_right(maze, pos) == 0)
    {
      pos[1] += 1;
      maze[pos[0]][pos[1]] = 'o';
      if (algo_depth2(maze, pos, size))
	return (1);
      pos[1] -= 1;
    }
  if (move_left(maze, pos) == 0)
    {
      pos[1] -= 1;
      maze[pos[0]][pos[1]] = 'o';
      if (algo_depth2(maze, pos, size))
	return (1);
      pos[1] += 1;
    }
  return (0);
}

int	algo_depth2(char **maze, int *pos, int size)
{
  if (pos[0] == size - 1 && (pos[1] == (int)strlen(maze[0]) - 1))
    return (1);
  if (algo_depth1(maze, pos, size))
    return (1);
  if (move_up(maze, pos) == 0)
    {
      pos[0] -= 1;
      maze[pos[0]][pos[1]] = 'o';
      if (algo_depth2(maze, pos, size))
	return (1);
      pos[0] += 1;
    }
  maze[pos[0]][pos[1]] = '#';
  return (0);
}
