##
## Makefile for makefile in /home/sachs_a/delivery/IA/dante/depth
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Fri Apr 21 17:48:55 2017 Alexandre Sachs
## Last update May May 11 14:21:05 2017
##

CC		= gcc

RM		= rm -rf

SRC_BIN		= ./src/main.c				\
		  ./src/depth/move.c			\
		  ./src/depth/depth.c			\
		  ./src/depth/my_open.c			\
		  ./src/depth/get_size.c		\
		  ./src/depth/algo_depth.c		\
		  ./src/depth/check_line.c		\
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
