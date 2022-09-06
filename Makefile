##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	source/end_laps.c           \
		source/main.c               \
		source/my_put.c             \
		source/wheels.c

INCLUDE =	-I include -o

CFLAGS	=	-Wall -Wextra -pedantic -g3

LIB	=	-g -lm

NAME	=	ai

all:	$(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all $(NAME) clean fclean re