##
## EPITECH PROJECT, 2019
## Makefile sources
## File description:
## Makefile Interface
##

CC		=	g++

RM		=	@rm -f

SRC		=	Main.cpp	\
			Usage.cpp	\
			Core.cpp	\
			Arcade.cpp	\
			Utils.cpp


OBJ		=	$(SRC:.cpp=.o)

%.o:%.cpp
		@$(CC) $(CPPFLAGS) -c -o  $@ $<

CPPFLAGS	=	-I../includes -Wall -Wextra

NAME		=	../arcade

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -ldl -o $(NAME) && \
		/bin/echo -e "\033[0;32m""Interface: "[OK]!"" "\033[00m" || \
		/bin/echo -e "\033[5;31m""Interface: "[KO]!""

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME) && \
		/bin/echo -e "\033[0;32m""Interface fclean: "[OK]!"""\033[00m"

re:		fclean all

.PHONY: all clean fclean re
