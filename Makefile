
##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	= my_functions.c \
	my_functions2.c \
	my_functions3.c \
	my_functions4.c \
	my_functions5.c \
	options.c \
	ls.c

CFLAGS	=	-g3
OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -ggdb3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
