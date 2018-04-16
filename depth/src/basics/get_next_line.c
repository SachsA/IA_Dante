/*
** get_next_line.c for gnl in /home/sachs_a/delivery/fonction_utiles/repo
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Thu Apr  6 23:39:21 2017 Alexandre Sachs
** Last update Thu Apr  6 23:39:21 2017 Alexandre Sachs
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int			my_strlen(char *str)
{
  int                   i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char			*my_malloc(int lengh)
{
  char			*str;
  int			i;

  i = 0;
  if ((str = malloc(sizeof(char *) * lengh)) == NULL)
    return (NULL);
  while (i++ < lengh)
    str[i] = '\0';
  return (str);
}

char			*my_addline(char *buffer, char *new_line,
				    int *pos, int comp)
{
  int			i;
  int			j;
  char			*str;
  int			lengh;

  i = -1;
  j = -1;
  lengh = my_strlen(new_line);
  if ((str = my_malloc(comp + lengh + 1)) == NULL)
    return (NULL);
  while (++i < lengh)
    str[i] = new_line[i];
  while (++j < comp)
    str[i + j] = buffer[*pos + j];
  str[i + j] = '\0';
  *pos = *pos + comp + 1;
  free(new_line);
  return (str);
}

char			*get_next_line(const int fd)
{
  static t_var_gnl	gnl = {0, 0, {0}};
  char			*new_line;
  int			comp;

  new_line = NULL;
  if (fd < 0)
    return (NULL);
  comp = -1;
  while (1)
    {
      ++comp;
      if (gnl.pos >= gnl.fin)
	{
	  gnl.pos = 0;
	  comp = 0;
	  if ((gnl.fin = read(fd, gnl.buffer, READ_SIZE)) == 0)
	    return (new_line);
	  if (gnl.fin < 0)
	    return (NULL);
	}
      if (gnl.buffer[gnl.pos + comp] == '\n')
	return (new_line = my_addline(gnl.buffer, new_line, &gnl.pos, comp));
      if (gnl.pos + comp == gnl.fin - 1)
	new_line = my_addline(gnl.buffer, new_line, &gnl.pos, comp + 1);
    }
}
