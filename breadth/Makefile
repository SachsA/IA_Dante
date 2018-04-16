##
## Makefile for breadth$ in /home/sachs_a/delivery/IA/dante/breadth
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Mon Apr 24 14:26:38 2017 Alexandre Sachs
## Last update May May 11 14:12:43 2017
##

CC		= gcc

RM		= rm -rf

SRC_BIN		= ./src/main.c				\
		  ./src/breadth/breadth.c		\
		  ./src/breadth/my_open.c		\
		  ./src/breadth/get_size.c		\
		  ./src/breadth/algo_breadth.c		\
		  ./src/breadth/check_line.c		\
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
