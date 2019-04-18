CC	=	gcc

RM	=	rm -f

SRCTEST = srcTest

SRC	=	src/tests_tab.c	\
		src/tests_err.c	\
		src/tests_compare.c	\
		../src/str_to_array.c	\
		../src/my_strncpy.c		\
		$(SRCTEST)/check_input.c

DIR_SRC = src

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../includes -Wall -Wextra

NAME	=	criterion

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lcriterion

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re