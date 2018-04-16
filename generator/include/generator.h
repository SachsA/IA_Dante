/*
** generator.h for Dante in /home/invicta/dante/generator/include/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Fri Apr 14 14:43:44 2017 Kellian CIPIERRE
** Last update Mar Apr 18 10:06:21 2017
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

/*
** STRUCTURES
*/
typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_maze
{
  char		**maze;
  int		height;
  int		width;
}		t_maze;

int	maze_generator(t_maze*, int);
int	maze_init(t_maze*);
int	is_in_tab(t_maze*, t_pos*);

#endif /* GENERATOR_H_ */
