/*
** depth.h for depthh in /home/sachs_a/delivery/IA/dante/depth
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Apr 21 17:53:10 2017 Alexandre Sachs
** Last update Fri Apr 21 17:53:10 2017 Alexandre Sachs
*/

#ifndef ASTAR_H_
# define ASTAR_H_

# define ADJ 10
# define DIA 14

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_maze
{
  int			h;
  int			g;
  int			f;
  t_pos			*size;
}			t_maze;

typedef struct		s_stack
{
  t_pos			pos;
  struct s_stack	*prev;
  struct s_stack	*next;
}			t_stack;

int			astar(int);
int			my_open(char **);
int			check_line(char *);
int			get_size(int, t_pos *);
int			heuris(t_maze ***, t_pos *);
int			fill_map(t_maze **, char *);
int			find_way(t_maze **, t_pos *);
int			init_list(t_stack **, t_pos *);
int			algo_astar(t_maze **, t_pos *);
int			push_list(t_stack **, t_stack *, t_pos *);

#endif /* !ASTAR_H_ */
