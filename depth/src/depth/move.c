/*
** move.c for move in /home/sachs_a/delivery/IA/dante/depth/src/depth
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 15:48:25 2017 Alexandre Sachs
** Last update Sun Apr 23 15:48:25 2017 Alexandre Sachs
*/

#include <string.h>

int	move_up(char **maze, int *pos)
{
  if (pos[0] - 1 < 0 || maze[pos[0] - 1][pos[1]] != '*')
    return (84);
  return (0);
}

int	move_down(char **maze, int *pos, int size)
{
  if (pos[0] + 1 >= size || maze[pos[0] + 1][pos[1]] != '*')
    return (84);
  return (0);
}

int	move_left(char **maze, int *pos)
{
  if (pos[1] - 1 < 0 || maze[pos[0]][pos[1] - 1] != '*')
    return (84);
  return (0);
}

int	move_right(char **maze, int *pos)
{
  int	size;

  size = strlen(maze[pos[0]]);
  if (pos[1] + 1 >= size || maze[pos[0]][pos[1] + 1] != '*')
    return (84);
  return (0);
}
