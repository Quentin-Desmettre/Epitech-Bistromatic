##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## Makefile for evaluation
##

SRC = eval_expr.c \
	evaluate_simple.c \
	get_prev_next.c

OBJ = $(SRC:.c=.o)

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../../include/

LIB = ../../lib/my/

all:
	gcc $(FLAGS) $(SRC) -I $(INCLUDE) -L $(LIB) -lmy
	cp $(OBJ) ../../

clean:
	rm -f $(OBJ)

re: clean all
