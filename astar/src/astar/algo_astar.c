/*
** algo_depth.c for algo_depth in /home/sachs_a/delivery/IA/dante/depth/src/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sun Apr 23 12:46:08 2017 Alexandre Sachs
** Last update May May 11 14:55:02 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "astar.h"
#include "basics.h"

int		update(t_maze **maze, t_stack **stack, t_pos *pos, int val)
{
  t_stack	*tmp;

  if (pos->y >= 0 && pos->x >= 0 &&
     pos->y < (*maze)->size->y && pos->x < (*maze)->size->x &&
     (maze[(*stack)->pos.y][pos->x].g == -1 ||
      maze[pos->y][(*stack)->pos.x].g == -1) &&
     maze[pos->y][pos->x].g == -1)
    {
      tmp = (*stack)->next;
      maze[pos->y][pos->x].g = maze[(*stack)->pos.y][(*stack)->pos.x].g + val;
      maze[pos->y][pos->x].f = maze[pos->y][pos->x].h + maze[pos->y][pos->x].g;
      while (tmp != NULL &&
	     maze[tmp->pos.y][tmp->pos.x].f < maze[pos->y][pos->x].f)
	tmp = tmp->next;
      if (push_list(stack, tmp, pos) == 84)
	return (84);
    }
  return (0);
}

int		update_adj(t_maze **maze, t_stack **stack)
{
  t_pos		pos;

  pos.y = (*stack)->pos.y - 1;
  pos.x = (*stack)->pos.x;
  if (update(maze, stack, &pos, ADJ) == 84)
    return (84);
  pos.y = (*stack)->pos.y + 1;
  if (update(maze, stack, &pos, ADJ) == 84)
    return (84);
  pos.y = (*stack)->pos.y;
  pos.x = (*stack)->pos.x + 1;
  if (update(maze, stack, &pos, ADJ) == 84)
  return (84);
  pos.x = (*stack)->pos.x - 1;
  if (update(maze, stack, &pos, ADJ) == 84)
    return (84);
  return (0);
}

int		update_dia(t_maze **maze, t_stack **stk)
{
  t_pos		pos;

  pos.y = (*stk)->pos.y - 1;
  pos.x = (*stk)->pos.x - 1;
  if (update(maze, stk, &pos, DIA) == 84)
    return (84);
  pos.x = (*stk)->pos.x + 1;
  if (update(maze, stk, &pos, DIA) == 84)
    return (84);
  pos.y = (*stk)->pos.y + 1;
  if (update(maze, stk, &pos, DIA) == 84)
    return (84);
  pos.x = (*stk)->pos.x - 1;
  if (update(maze, stk, &pos, DIA) == 84)
    return (84);
  return (0);
}

int		algo_astar(t_maze **maze, t_pos *size)
{
  t_pos		pos;
  t_stack	*stack;

  pos = (t_pos) {0, 0};
  maze[pos.y][pos.x].g = 0;
  maze[pos.y][pos.x].f = maze[pos.y][pos.x].h + maze[pos.y][pos.x].g;
  stack = NULL;
  init_list(&stack, &pos);
  while (maze[pos.y][pos.x].h != 0 && stack != NULL)
    {
      maze[pos.y][pos.x].size = size;
      if (update_dia(maze, &stack) == 84 || update_adj(maze, &stack) == 84)
	return (84);
      stack = stack->next;
      if (stack != NULL)
	pos = stack->pos;
      else
	return (printf("Sorry there is no solution.\n"), 84);
    }
  return (0);
}
