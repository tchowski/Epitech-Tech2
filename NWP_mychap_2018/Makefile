##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c				\
		help.c				\
		utils.c				\
		errors.c			\
		xsetsockopt.c		\
		init.c				\
		socket.c			\
		hostname_to_ip.c	\
		sha256.c			\
		xbind.c				\
		run.c				\
		print_fill.c		\
		xsendfrom.c			\
		xrecvfrom.c			\

DIR_SRC = src

OBJ	=	$(addprefix $(DIR_SRC)/, $(SRC:.c=.o))

CFLAGS	=	-Iinclude -Wall -Wextra -Werror

NAME	=	client

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lcrypto

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re