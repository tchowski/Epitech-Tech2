##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	libasm.so

DIR_SRC	=	src

SRCS	=	strlen.asm	\
			strnlen.asm	\
			strcmp.asm	\
			strncmp.asm	\
			memmove.asm	\
			memcpy.asm	\
			memset.asm

RM		=	rm -f

OBJ		=	$(addprefix $(DIR_SRC)/, $(SRCS:.asm=.o))

%.o: %.asm
			nasm -o $@ $< -f elf64

all:	$(NAME)

$(NAME):	$(OBJ)
			ld -shared -fPIC -o $(NAME) $(OBJ)
			# gcc src/main.c -o tests $(NAME)

test:
			$(MAKE) re -C ./tests
			cp tests/Moulinette .

clean:
			$(RM) src/*.o

fclean:	clean
			$(RM) $(NAME)
			$(RM) Moulinette

re:	fclean all

.PHONY:	all clean fclean re