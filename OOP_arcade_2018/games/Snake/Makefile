##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## Makefile
##

CC		=	g++

RM		=	@rm -f

SRC		=	Snake.cpp

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I../includes_games/Snake -Wall -Wextra -fPIC -shared

NAME		=	../lib_arcade_snake.so

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME) && \
		/bin/echo -e "\033[0;32m""Lib Snake: "[OK]!"" "\033[00m" || \
		/bin/echo -e "\033[5;31m""Lib Snake: "[KO]!""

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME) && \
		/bin/echo -e "\033[0;32m""Remove Snake files"[OK]!"""\033[00m"

re:		fclean all

.PHONY: all clean fclean re
