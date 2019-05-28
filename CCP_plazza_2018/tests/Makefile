##
## EPITECH PROJECT, 2019
## NWP_myftp_2018
## File description:
## Makefile
##

NAME 	=	unit_tests

SDIR	=	../src

SRC		=	$(SDIR)/Reception.cpp		\
			$(SDIR)/Message_q.cpp		\
			$(SDIR)/Process.cpp			\
			$(SDIR)/Kitchen.cpp			\
			TestReception.cpp

OBJ		=	$(SRC:.cpp=.o)

GXX		=	g++

RM		=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -lrt

CPPFLAGS	=	-lcriterion -pthread -I../includes

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GXX) $(CPPFLAGS) $^ -o $@ -lrt

tests_run:	$(NAME)
	./$<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

rclean:
	$(RM) vgcore.*
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean	all

rerun: re tests_run

.PHONY:	all tests_run clean fclean rclean re rerun