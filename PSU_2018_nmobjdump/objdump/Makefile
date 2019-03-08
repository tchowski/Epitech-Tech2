CC	=	gcc

RM	=	rm -f

SRC	=	main.c	\
		check_errors.c	\
		objdump.c		\

DIR_SRC = src

OBJ	=	$(addprefix $(DIR_SRC)/, $(SRC:.c=.o))

CFLAGS	=	-Iinclude -Wall -Wextra -Werror

NAME	=	my_objdump

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re