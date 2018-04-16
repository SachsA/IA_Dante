/*
** maze_generator.c for Dante in /home/invicta/dante/generator/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Fri Apr 14 14:38:34 2017 Kellian CIPIERRE
** Last update Tue May  9 10:26:20 2017 Kellian CIPIERRE
*/

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int	check_adjacent(t_maze *maze, t_pos *pos)
{
  int	i;

  i = 0;
  if (pos->x >= 0 && pos->y - 1 >= 0 &&
      pos->x < maze->width && pos->y - 1 < maze->height &&
      maze->maze[pos->y - 1][pos->x] != 'X')
    i++;
  if (pos->x + 1 >= 0 && pos->y >= 0 &&
      pos->x + 1 < maze->width && pos->y < maze->height &&
      maze->maze[pos->y][pos->x + 1] != 'X')
    i++;
  if (pos->x >= 0 && pos->y + 1 >= 0 &&
      pos->x < maze->width && pos->y + 1 < maze->height &&
      maze->maze[pos->y + 1][pos->x] != 'X')
    i++;
  if (pos->x - 1 >= 0 && pos->y >= 0 &&
      pos->x - 1 < maze->width && pos->y < maze->height &&
      maze->maze[pos->y][pos->x - 1] != 'X')
    i++;
  return (i);
}

int	verif_adjacent(t_maze *maze, t_pos *pos)
{
  t_pos	tmp;

  tmp.y = pos->y - 1;
  tmp.x = pos->x;
  if (is_in_tab(maze, &tmp) &&
      check_adjacent(maze, &tmp) == 1)
    return (1);
  tmp.y = pos->y + 1;
  if (is_in_tab(maze, &tmp) &&
      check_adjacent(maze, &tmp) == 1)
    return (1);
  tmp.y = pos->y;
  tmp.x = pos->x - 1;
  if (is_in_tab(maze, &tmp) &&
      check_adjacent(maze, &tmp) == 1)
    return (1);
  tmp.x = pos->x + 1;
  if (is_in_tab(maze, &tmp) &&
      check_adjacent(maze, &tmp) == 1)
    return (1);
  return (0);
}

int	update_pos(t_maze *maze, t_pos *pos)
{
  t_pos	save;
  int	way;
  int	val;

  save.y = pos->y;
  save.x = pos->x;
  way = rand() % 2;
  val = (rand() % 2) * 2 - 1;
  if (way == 0)
    pos->y += val;
  else
    pos->x += val;
  while (is_in_tab(maze, pos) == 0 || check_adjacent(maze, pos) > 1 ||
	 maze->maze[pos->y][pos->x] == '*')
    {
      pos->y = save.y;
      pos->x = save.x;
      way = rand() % 2;
      val = (rand() % 2) * 2 - 1;
      if (way == 0)
	pos->y += val;
      else
	pos->x += val;
    }
  return (1);
}

int	maze_draw(t_maze *maze, t_pos *ori)
{
  t_pos	pos;

  srand(time(NULL));
  pos.y = ori->y;
  pos.x = ori->x;
  while ((pos.y == 0 && pos.x == 0) ||
	 ((verif_adjacent(maze, &pos)) == 1 &&
	 (pos.y != maze->height - 1 && pos.x != maze->width - 1)))
    {
      update_pos(maze, &pos);
      maze->maze[pos.y][pos.x] = '*';
    }
  return (0);
}

int	maze_generator(t_maze *maze, int opt)
{
  t_pos	pos;

  pos.y = 0;
  while (pos.y < maze->height)
    {
      pos.x = 0;
      while (pos.x < maze->width)
	{
	  if ((pos.y == 0 && pos.x == 0) ||
	      (maze->maze[pos.y][pos.x] == 'X' &&
	      ((check_adjacent(maze, &pos) == 1) ||
	       (opt == 1 && check_adjacent(maze, &pos) == 2))))
	    {
	      maze->maze[pos.y][pos.x] = '*';
	      maze_draw(maze, &pos);
	    }
	  pos.x++;
	}
      pos.y++;
    }
  return (0);
}
