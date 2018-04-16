/*
** my_free_tab.c for my_free_tab in /home/sachs_a/delivery/IA/dante/depth/src/
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 11:16:10 2017 Alexandre Sachs
** Last update Sun Apr 23 11:16:10 2017 Alexandre Sachs
*/

#include <stdlib.h>

void	my_free_tab(int **tab)
{
  int	i;

  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    free(tab[i]);
  if (tab != NULL)
    free(tab);
}
