##
## EPITECH PROJECT, 2019
## Makefile general
## File description:
## Makefile
##

all:	general

general:
		@$(MAKE) --no-print-directory -C sources
		@$(MAKE) --no-print-directory -C lib
		@$(MAKE) --no-print-directory -C games

core:
		@$(MAKE) --no-print-directory -C sources

graphicals:
		@$(MAKE) --no-print-directory -C lib

games:
		@$(MAKE) --no-print-directory -C games

clean:
		@$(MAKE) clean --no-print-directory -C sources
		@$(MAKE) clean --no-print-directory -C lib
		@$(MAKE) clean --no-print-directory -C games

fclean:
		@$(MAKE) fclean --no-print-directory -C sources
		@$(MAKE) fclean --no-print-directory -C lib
		@$(MAKE) fclean --no-print-directory -C games

re:
		@$(MAKE) re --no-print-directory -C sources
		@$(MAKE) re --no-print-directory -C lib
		@$(MAKE) re --no-print-directory -C games

.PHONY: all clean fclean re games