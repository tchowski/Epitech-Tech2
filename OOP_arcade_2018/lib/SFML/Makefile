##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## Makefile
##

CC		=	g++

RM		=	@rm -f

SRC		=	SFML.cpp

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I../includes_lib/SFML -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -fPIC -shared

NAME		=	../lib_arcade_SFML.so

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME) && \
		/bin/echo -e "\033[0;32m""Lib SFML: "[OK]!"" "\033[00m" || \
		/bin/echo -e "\033[5;31m""Lib SFML: "[KO]!""

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME) && \
		/bin/echo -e "\033[0;32m""Remove SFML files"[OK]!"""\033[00m"

re:		fclean all

.PHONY: all clean fclean re
