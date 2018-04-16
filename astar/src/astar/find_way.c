/*
** find_way.c for find_way in /home/sachs_a/delivery/IA/dante/astar
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat May  6 15:03:50 2017 Alexandre Sachs
** Last update May May 11 14:49:51 2017
*/

#include <stdio.h>
#include "astar.h"

int	move(t_maze **maze, int y, int x)
{
  if (y >= 0 && x >= 0 &&
      y < (**maze).size->y && x < (**maze).size->x &&
      maze[y][x].g >= 0)
    return (1);
  return (0);
}

int	update_pos(t_maze **maze, t_pos *pos)
{
  t_pos	tmp;

  tmp.y = pos->y;
  tmp.x = pos->x;
  if (move(maze, pos->y - 1, pos->x) &&
      maze[pos->y - 1][pos->x].g <= maze[tmp.y][tmp.x].g)
    tmp.y = pos->y - 1;
  if (move(maze, pos->y + 1, pos->x) &&
      maze[pos->y + 1][pos->x].g <= maze[tmp.y][tmp.x].g)
    tmp.y = pos->y + 1;
  if (move(maze, pos->y, pos->x - 1) &&
      maze[pos->y][pos->x - 1].g <= maze[tmp.y][tmp.x].g)
    {
      tmp.y = pos->y;
      tmp.x = pos->x - 1;
    }
  if (move(maze, pos->y, pos->x + 1) &&
      maze[pos->y][pos->x + 1].g <= maze[tmp.y][tmp.x].g)
    {
      tmp.y = pos->y;
      tmp.x = pos->x + 1;
    }
  pos->y = tmp.y;
  pos->x = tmp.x;
  return (0);
}

int	find_way(t_maze **maze, t_pos *size)
{
  t_pos	pos;

  pos.y = size->y - 1;
  pos.x = size->x - 1;
  while (maze[pos.y][pos.x].g != 0)
    {
      maze[pos.y][pos.x].f = 0;
      update_pos(maze, &pos);
    }
  maze[pos.y][pos.x].f = 0;
  return (0);
}
