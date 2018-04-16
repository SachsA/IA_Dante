/*
** my_show_wordtab.c for show_wordtab in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Thu Apr  6 23:40:05 2017 Alexandre Sachs
** Last update Feb Apr 24 18:38:54 2017
*/

#include <stdio.h>

int	my_show_wordtab(int **tab)
{
  int	i;
  int	j;

  i = -1;
  while (tab[++i] != NULL)
    {
      j = 0;
      while (tab[i][j] != -3)
	{
	  if (tab[i][j] == -2)
	    printf("X");
	  else if (tab[i][j] == 0)
	    printf("o");
	  else
	    printf("*");
	  j++;
	}
      printf("\n");
    }
  return (0);
}
