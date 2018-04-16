/*
** my_show_wordtab.c for show_wordtab in /home/sachs_a/delivery/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Thu Apr  6 23:40:05 2017 Alexandre Sachs
** Last update Thu Apr  6 23:40:05 2017 Alexandre Sachs
*/

#include "astar.h"
#include <stdio.h>

int	my_show_wordtab_h(t_maze **tab, t_pos *size)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size->y)
    {
      j = -1;
      while (++j < size->x)
	printf("%d\t", tab[i][j].h);
      printf("\n");
    }
  return (0);
}

int	my_show_wordtab_g(t_maze **tab, t_pos *size)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size->y)
    {
      j = -1;
      while (++j < size->x)
	printf("%d\t", tab[i][j].g);
      printf("\n");
    }
  return (0);
}

int	my_show_wordtab_f(t_maze **tab, t_pos *size)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size->y)
    {
      j = -1;
      while (++j < size->x)
	printf("%d\t", tab[i][j].f);
      printf("\n");
    }
  return (0);
}

int	my_show_wordtab_end(t_maze **tab, t_pos *size)
{
  int	i;
  int	j;

  i = -1;
  while (++i < size->y)
    {
      j = -1;
      while (++j < size->x)
	{
	  if (tab[i][j].f == 0)
	    printf("o");
	  else if (tab[i][j].f == -2)
	    printf("X");
	  else
	    printf("*");
	  if (j < size->x - 1)
	    printf(" ");
	}
      printf("\n");
    }
  return (0);
}
