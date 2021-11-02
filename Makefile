##
## EPITECH PROJECT, 2021
## Bistro-matic
## File description:
## makefile
##

NAME = calc

LIBS = -L ./lib/my/ -lmy

all:
	make -C ./lib/my/ && make -C ./lib/my/ clean
	make -C ./src/
	gcc -o $(NAME) *.o $(LIBS) -lm

tests_run:
	make -C ./lib/my/ && make -C ./lib/my/ clean
	make -C ./src/ tests
	gcc -o unit_tests *.o $(LIBS) --coverage -lcriterion
	./unit_tests

clean:
	rm -f *.o
	make -C ./src/ clean
	find . -name *.gcno -delete
	find . -name *.gcda -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
