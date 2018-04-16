/*
** maze_init.c for Dante in /home/invicta/dante/generator/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Fri Apr 14 14:39:18 2017 Kellian CIPIERRE
** Last update Jun Apr 14 19:39:38 2017
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int	maze_init(t_maze *maze)
{
  int	i;

  if ((maze->maze = malloc(sizeof(char*) * maze->height)) == NULL)
    return (0);
  i = 0;
  while (i < maze->height)
    {
      maze->maze[i] = malloc(sizeof(char) * maze->width + 1);
      memset(maze->maze[i], 88, maze->width);
      maze->maze[i][maze->width] = '\0';
      i++;
    }
  return (1);
}
