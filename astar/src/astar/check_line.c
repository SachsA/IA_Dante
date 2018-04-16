/*
** check_line.c for check_line in /home/sachs_a/delivery/IA/dante/depth/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 10:44:00 2017 Alexandre Sachs
** Last update Sun Apr 23 10:44:00 2017 Alexandre Sachs
*/

#include <unistd.h>

int	check_line(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] != 'X' && str[i] != '*')
      {
	write(2, "The file must be a map with : 'X' for the walls "
		 "and '*' for the spaces.\n", 72);
	return (84);
      }
  return (0);
}
