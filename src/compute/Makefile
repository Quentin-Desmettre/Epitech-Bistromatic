##
## EPITECH PROJECT, 2021
## bistromatic
## File description:
## makefile for computations
##

SRC = doop.c

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
