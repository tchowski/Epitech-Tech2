##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c			\
		check_errors.c	\
		strace.c		\
		open_file.c		\
		usage.c			\
		wait_pid.c		\
		print_struct.c

DIR_SRC = src

OBJ	=	$(addprefix $(DIR_SRC)/, $(SRC:.c=.o))

CFLAGS	=	-Iinclude -Wall -Wextra -Werror

NAME	=	ftrace

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
