##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = main.c

OBJ = $(SRC:.c=.o)

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../include

LIB = ../lib/my

all:
	make -C check/
	gcc $(FLAGS) $(SRC) -I $(INCLUDE) -L $(LIB) -lmy
	cp $(OBJ) ../

clean:
	rm -f $(OBJ)
	make -C check/ clean

re: clean all
