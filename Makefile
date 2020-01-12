##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_ls
##

NAME	=	my_ls

SRC	=	src/main.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/flag_d.c \
		src/display_color.c \
		src/simple_ls.c \
		src/check_flag.c \
		src/flag_rmaj.c \
		src/my_strlen.c \
		src/flag_t.c \
		src/swap_elem.c \
		src/display.c \
		src/flag_t_arg.c \
		src/flag_l.c \
		src/right_print.c \
		src/my_strcat.c \
		src/my_put_nbr.c

CC	=	gcc

DEFLAGS	=	-W -Wextra -Wall -g3

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(DEFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

TU	:
		$(CC) -o unit_tests lib/my/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *# \
		rm -f src/*# \
		rm -f include/*# \
		rm -f *~ \
		rm -f src/*~ \
		rm -f include/*~ \
		rm -f *.gcda \
		rm -f *.gcno

re	:	fclean all

.PHONY	:	all TU clean fclean re
