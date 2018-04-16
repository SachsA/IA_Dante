/*
** my_free.c for my_free in /home/sachs_a/delivery/IA/dante/depth/src/basics
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 11:12:15 2017 Alexandre Sachs
** Last update Sun Apr 23 11:12:15 2017 Alexandre Sachs
*/

#include <stdlib.h>
#include "basics.h"

void	free_depth(char *str, char **maze)
{
  if (str != NULL)
    {
      free(str);
      str = NULL;
    }
  if (maze != NULL)
    my_free_tab(maze);
}
