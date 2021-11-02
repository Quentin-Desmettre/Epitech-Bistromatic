##
## EPITECH PROJECT, 2021
## bistromatic
## File description:
## makefile for add
##

SRC = div.c

OBJ = $(SRC:.c=.o)

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../../../include/

LIB = ../../../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../../../

clean:
	rm -f $(OBJ)
