/*
** in_in_tab.c for Dante in /home/invicta/dante/generator/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Fri Apr 14 20:41:25 2017 Kellian CIPIERRE
** Last update Mar Apr 18 08:53:16 2017
*/

#include "generator.h"

int	is_in_tab(t_maze *maze, t_pos *pos)
{
  if (pos->y < 0 ||
      pos->x < 0 ||
      pos->y >= maze->height ||
      pos->x >= maze->width)
    return (0);
  return (1);
}
