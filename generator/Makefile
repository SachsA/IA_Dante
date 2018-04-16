##
## Makefile for Makefile in /home/sachs_a/delivery/IA/dante/generator
##
## Made by Alexandre Sachs
## Login   <sachs_a@epitech.net>
##
## Started on  Sun Apr 23 16:51:18 2017 Alexandre Sachs
## Last update May May 11 14:23:00 2017
##

SHELL		= bash

CC		= gcc -g

RM		= rm -rf

SRC_BIN		= ./src/main.c			\
		  ./src/is_in_tab.c		\
		  ./src/maze_init.c		\
		  ./src/maze_generator.c

OBJ_BIN		= $(SRC_BIN:.c=.o)

CFLAGS		+= -I ./include/
CFLAGS		+= -W -Wall -Wextra -Werror

NAME_BIN	= ./generator

$(NAME_BIN):	$(OBJ_BIN)
		$(CC) -o $(NAME_BIN) $(OBJ_BIN)

all:		$(NAME_BIN)

clean:
		$(RM) $(OBJ_BIN)

fclean:		clean
		$(RM) $(NAME_BIN)

re:		fclean all

.PHONY:		all clean fclean re
