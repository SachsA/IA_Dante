/*
** get_size.c for get_size in /home/sachs_a/delivery/IA/dante/depth/src/depth
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 12:36:09 2017 Alexandre Sachs
** Last update Sun Apr 23 12:36:09 2017 Alexandre Sachs
*/

#include "get_next_line.h"

int	get_size(int fd)
{
  int	pos;
  char	*str;

  pos = 0;
  while ((str = get_next_line(fd)))
    {
      pos++;
      free(str);
    }
  return (pos);
}
