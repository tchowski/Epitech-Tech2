##
## EPITECH PROJECT, 2019
## deBruijn
## File description:
## Makefile
##

RM		=	rm -rf

all:	deBruijn

deBruijn:
		stack build --copy-bins --local-bin-path .

clean:
		stack clean
		$(RM) .stack-work deBruijn.cabal
		$(RM) deBruijn

fclean: clean

re:		fclean all

.PHONY:	all clean fclean re