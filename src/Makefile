##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = main.c \
		bistromatic.c

TESTS = ../tests/test_check.c

OBJ = $(SRC:.c=.o)

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../include

LIB = ../lib/my

all:
	make -C check/
	make -C compute/
	make -C evaluate/
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../

tests:
	make -C check/ tests
	make -C compute/ tests
	make -C evaluate/ tests
	gcc $(FLAGS) -I $(INCLUDE) bistromatic.c $(TESTS) -L $(LIB) -lmy --coverage -lcriterion
	cp *.o ../

clean:
	rm -f *.o
	make -C check/ clean
	make -C compute/ clean
	make -C evaluate/ clean

re: clean all
