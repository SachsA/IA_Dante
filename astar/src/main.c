/*
** main.c for astar in /home/sachs_a/delivery/IA/dante/astar/src
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Mon Apr 24 14:07:18 2017 Alexandre Sachs
** Last update Mon Apr 24 14:07:18 2017 Alexandre Sachs
*/

#include <unistd.h>
#include "astar.h"

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
  if (astar(fd) == 84)
    return (84);
  return (0);
}
