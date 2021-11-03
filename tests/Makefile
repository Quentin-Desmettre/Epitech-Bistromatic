##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = test_check.c \
	test_check_expr.c \
	test_check_expr_others.c \
	test_mul.c

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../include/

LIB = ../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy --coverage -lcriterion
	cp *.o ../

clean:
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
