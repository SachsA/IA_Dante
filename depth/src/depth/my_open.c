/*
** my_open.c for my_open in /home/sachs_a/delivery/IA/dante/depth/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Apr 21 18:00:42 2017 Alexandre Sachs
** Last update Fri Apr 21 18:00:42 2017 Alexandre Sachs
*/

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int		my_open(char **argv)
{
  int		fd;
  struct stat	st;

  if (stat(argv[1], &st) == 0)
    {
      if (S_ISDIR(st.st_mode))
	return (write(2, "It's not a file.\n", 17), -1);
      if (st.st_size == 0)
	return (write(2, "This file is empty.\n", 20), -1);
    }
  if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
      write(2, strerror(errno), strlen(strerror(errno)));
      write(2, "\n", 1);
      return (-1);
    }
  return (fd);
}
