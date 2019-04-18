##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c	\
		usage.c	\
		str_to_array.c	\
		str_to_comma.c	\
		socket.c		\
		init_struct.c	\
		utils.c			\
		utils2.c		\
		user.c			\
		my_strncpy.c	\
		directories.c	\
		command.c		\
		data.c			\
		data_command.c

DIR_SRC = src

OBJ	=	$(addprefix $(DIR_SRC)/, $(SRC:.c=.o))

CFLAGS	=	-Iincludes -Wall -Wextra -Werror

NAME	=	myftp

all:		$(NAME)
		$(MAKE) -C tests

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re ftp