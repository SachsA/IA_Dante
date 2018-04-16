/*
** depth.h for depthh in /home/sachs_a/delivery/IA/dante/depth
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Fri Apr 21 17:53:10 2017 Alexandre Sachs
** Last update Fri Apr 21 17:53:10 2017 Alexandre Sachs
*/

#ifndef DEPTH_H_
# define DEPTH_H_

int	depth(int);
int     get_size(int);
int	my_open(char **);
int     check_line(char *);
int     move_up(char **, int *);
int     move_left(char **, int *);
int     move_right(char **, int *);
int     move_down(char **, int *, int);
int	algo_depth1(char **, int *, int);
int	algo_depth2(char **, int *, int);

#endif /* !DEPTH_H_ */
