/*
** main.c for main in /home/sachs_a/delivery/IA/dante/depth/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Apr 21 17:52:41 2017 Alexandre Sachs
** Last update Fri Apr 21 17:52:41 2017 Alexandre Sachs
*/

#include <unistd.h>
#include "depth.h"

int	main(int argc, char **argv)
{
  int	fd;

  if (argc != 2)
    {
      write(2, "There must be 2 arguments : the binary and the file.\n", 53);
      return (84);
    }
  if ((fd = my_open(argv)) == -1)
    return (84);
  if (depth(fd) == 84)
    return (84);
  return (0);
}
