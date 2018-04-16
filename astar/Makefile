##
## Makefile for make in /home/sachs_a/delivery/IA/dante/astar
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Mon Apr 24 14:05:18 2017 Alexandre Sachs
## Last update May May 11 14:12:39 2017
##

CC		= gcc

RM		= rm -rf

SRC_BIN		= ./src/main.c				\
		  ./src/astar/list.c			\
		  ./src/astar/astar.c			\
		  ./src/astar/my_open.c			\
		  ./src/astar/find_way.c		\
		  ./src/astar/fill_map.c		\
		  ./src/astar/get_size.c		\
		  ./src/astar/algo_astar.c		\
		  ./src/astar/check_line.c		\
		  ./src/basics/my_free.c		\
		  ./src/basics/my_free_tab.c		\
		  ./src/basics/get_next_line.c		\
		  ./src/basics/my_show_wordtab.c

OBJ_BIN		= $(SRC_BIN:.c=.o)

CFLAGS		+= -I ./include/
CFLAGS		+= -W -Wall -Wextra -Werror -g

NAME_BIN	= ./solver

$(NAME_BIN):	$(OBJ_BIN)
		$(CC) -o $(NAME_BIN) $(OBJ_BIN)

all:		$(NAME_BIN)

clean:
		$(RM) $(OBJ_BIN)

fclean:		clean
		$(RM) $(NAME_BIN)

re:		fclean all

.PHONY:		all clean fclean re
