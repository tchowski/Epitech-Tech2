##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## Makefile
##

CC		=	g++

RM		=	@rm -f

SRC		=	SDL.cpp

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I../includes_lib/SDL -Wall -Wextra -lSDL2 -lSDL2main -fPIC -shared

NAME		=	../lib_arcade_SDL.so

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME) && \
		/bin/echo -e "\033[0;32m""Lib SDL: "[OK]!"" "\033[00m" || \
		/bin/echo -e "\033[5;31m""Interface: "[KO]!""

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME) && \
		/bin/echo -e "\033[0;32m""Remove SDL files: "[OK]!"""\033[00m"

re:		fclean all

.PHONY: all clean fclean re
