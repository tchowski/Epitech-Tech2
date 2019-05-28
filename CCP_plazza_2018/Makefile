##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=	g++ -g3 -std=c++11

RM		=	rm -f

SRC		=	Main.cpp	\
			Pizza.cpp	\
			Utils.cpp	\
			Mutex.cpp	\
			Reception.cpp	\
			ConditionVariableMutex.cpp	\
			Kitchen.cpp					\
			Message_q.cpp				\
			Process.cpp					\
			Thread.cpp					\
			ThreadPool.cpp

DIR_SRC	=	src

DIR_TEST	=	tests

OBJ	=   $(addprefix $(DIR_SRC)/, $(SRC:.cpp=.o))

CPPFLAGS	=	-Iincludes -Iincludes/Pizzaincludes -Wall -Wextra

NAME		=	plazza

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -pthread -lrt -lpthread
		# make -C $(DIR_TEST)

# tests_run:	all
# 	make rerun -C $(DIR_TEST)

clean:
		$(RM) $(OBJ)
		# make clean -C $(DIR_TEST)

fclean:		clean
		$(RM) $(NAME)
		# make fclean -C $(DIR_TEST)

re:		fclean all
		# make re -C $(DIR_TEST)

.PHONY: all clean fclean re