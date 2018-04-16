/*
** basics.h for basics in /home/sachs_a/delivery/IA/dante/depth/include
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sun Apr 23 11:13:08 2017 Alexandre Sachs
** Last update Sun Apr 23 11:13:08 2017 Alexandre Sachs
*/

#ifndef BASICS_H_
# define BASICS_H_

# include "astar.h"

void	my_free_tab(t_maze **);
void	free_astar(char *, t_maze **);
int     my_show_wordtab_h(t_maze **, t_pos *);
int     my_show_wordtab_g(t_maze **, t_pos *);
int     my_show_wordtab_f(t_maze **, t_pos *);
int     my_show_wordtab_end(t_maze **, t_pos *);

#endif /* !BASICS_H_ */
