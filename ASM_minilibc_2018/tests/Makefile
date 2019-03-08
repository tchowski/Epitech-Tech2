##
## EPITECH PROJECT, 2019
## Makefile minilibC
## File description:
## Makefile
##

NAME	=	libasm.so

DIR_SRC	=	src

SRCS	=	strlen.asm	\
			strnlen.asm	\
			strcmp.asm	\
			strncmp.asm	\
			memset.asm	\
			memcpy.asm

RM		=	rm -f

OBJ		=	$(addprefix $(DIR_SRC)/, $(SRCS:.asm=.o))

%.o: %.asm
			nasm -o $@ $< -f elf64

all:		$(NAME)

$(NAME):	$(OBJ)
			ld -shared -fPIC -o $(NAME) $(OBJ)
			gcc src/main.c -o Moulinette $(NAME)

clean:
			$(RM) src/*.o
			$(RM) Moulinette

fclean:	clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re