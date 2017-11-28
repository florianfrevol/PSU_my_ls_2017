##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	my_ls.c				\
		src.c

OBJ	=	$(SRC:.c=.o)

NAME	=	./my_ls

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *#
	rm -f *~
fclean: clean
	rm -f $(NAME)

re: fclean all
