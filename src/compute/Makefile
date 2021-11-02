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
	make -C add/
	make -C sub/
	make -C mul/
	make -C div/
#	make -C mod/
	gcc $(FLAGS) $(SRC) -I $(INCLUDE) -L $(LIB) -lmy
	cp $(OBJ) ../../

clean:
	make -C add/ clean
	make -C sub/ clean
	make -C mul/ clean
	make -C div/ clean
#	make -C mod/ clean
	rm -f $(OBJ)

re: clean all
