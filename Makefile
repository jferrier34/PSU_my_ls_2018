
##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	= my_functions.c \
	my_functions2.c \
	my_functions3.c \
	options.c \
	ls.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
