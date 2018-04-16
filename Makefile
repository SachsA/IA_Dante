##
## Makefile for Dante in /home/invicta/dante/
##
## Made by Kellian CIPIERRE
## Login   <kellian.cipierre@epitech.eu>
##
## Started on  Thu May 11 13:41:05 2017 Kellian CIPIERRE
## Last update May May 11 14:22:00 2017
##

MK		=	make -s

ASTAR		=	./astar

DEPTH		=	./depth

BREADTH		=	./breadth

GENERATOR	=	./generator

TOURNAMENT	=	./tournament

all:
	$(MK) -C $(ASTAR)
	$(MK) -C $(DEPTH)
	$(MK) -C $(BREADTH)
	$(MK) -C $(GENERATOR)
	$(MK) -C $(TOURNAMENT)

clean:
	$(MK) clean -C $(ASTAR)
	$(MK) clean -C $(DEPTH)
	$(MK) clean -C $(BREADTH)
	$(MK) clean -C $(GENERATOR)
	$(MK) clean -C $(TOURNAMENT)

fclean:
	$(MK) fclean -C $(ASTAR)
	$(MK) fclean -C $(DEPTH)
	$(MK) fclean -C $(BREADTH)
	$(MK) fclean -C $(GENERATOR)
	$(MK) fclean -C $(TOURNAMENT)


re:
	$(MK) re -C $(ASTAR)
	$(MK) re -C $(DEPTH)
	$(MK) re -C $(BREADTH)
	$(MK) re -C $(GENERATOR)
	$(MK) re -C $(TOURNAMENT)

.PHONY:	all clean fclean re
