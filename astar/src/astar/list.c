/*
** list.c for list in /home/sachs_a/delivery/IA/dante/astar/src/astar
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sat May  6 14:42:40 2017 Alexandre Sachs
** Last update Sat May  6 14:42:40 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "astar.h"

int		init_list(t_stack **stack, t_pos *pos)
{
  t_stack       *new;

  if ((new = malloc(sizeof(t_stack))) == NULL)
    return (84);
  new->pos = *pos;
  new->prev = NULL;
  new->next = NULL;
  *stack = new;
  return (0);
}

int		push_list(t_stack **stack, t_stack *tmp, t_pos *pos)
{
  t_stack       *tmp2;
  t_stack       *new;

  if ((new = malloc(sizeof(t_stack))) == NULL)
    return (84);
  new->pos = *pos;
  if (tmp == NULL)
    {
      tmp2 = (*stack);
      while (tmp2->next != NULL)
        tmp2 = tmp2->next;
      tmp2->next = new;
      new->next = NULL;
      new->prev = tmp2;
      return (0);
    }
  new->next = tmp;
  new->prev = tmp->prev;
  tmp->prev = new;
  new->prev->next = new;
  return (0);
}
