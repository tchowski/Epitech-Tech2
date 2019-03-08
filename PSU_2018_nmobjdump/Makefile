CC	=	gcc

RM	=	rm -f

all:
		@$(MAKE) -C ./nm
		cp ./nm/my_nm .
		@$(MAKE) -C ./objdump
		cp ./objdump/my_objdump .

nm:
		$(MAKE) -C ./nm
		cp ./nm/my_nm .

objdump:
		$(MAKE) -C ./objdump
		cp ./objdump/my_objdump .

clean:
		$(RM) my_nm
		$(RM) my_objdump
		$(MAKE) clean -C ./nm
		$(MAKE) clean -C ./objdump

fclean:	clean

		$(MAKE) fclean -C ./nm
		$(MAKE) fclean -C ./objdump

re:		fclean all

.PHONY: all clean fclean re nm objdump