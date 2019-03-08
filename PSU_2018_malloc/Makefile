CC	=	gcc

RM	=	rm -f

DIR_SRC = src

SRC	= src/malloc.c

OBJ	=   $(addprefix $(DIR_SRC)/, $(SRC:.c=.o))

CPPFLAGS =	-I./include

NAME	=	libmy_malloc.so

FLAGS	= -fPIC -shared

all:		$(NAME)

$(NAME):
		$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re