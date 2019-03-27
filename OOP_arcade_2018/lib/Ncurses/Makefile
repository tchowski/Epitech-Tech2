##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## Makefile
##

CC		=	g++

RM		=	@rm -f

SRC		=	Ncurses.cpp

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I../includes_lib/Ncurses -Wall -Wextra -fPIC -shared -lncurses

NAME		=	../lib_arcade_Ncurses.so

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME) && \
		/bin/echo -e "\033[0;32m""Lib Ncurses: "[OK]!"" "\033[00m" || \
		/bin/echo -e "\033[5;31m""Lib Ncurses: "[KO]!""

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME) && \
		/bin/echo -e "\033[0;32m""Remove Ncurses files: "[OK]!"""\033[00m"

re:		fclean all

.PHONY: all clean fclean re
