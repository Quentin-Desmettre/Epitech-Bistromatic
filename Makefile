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
	gcc -o $(NAME) *.o $(LIBS)

tests_run: fclean
	make -C ./lib/my/ && make -C ./lib/my/ clean
	make -C ./src/ tests
	make -C ./tests/
	gcc -o unit_tests *.o $(LIBS) --coverage -lcriterion
	./unit_tests

clean:
	rm -f *.o
	make -C ./src/ clean
	make -C ./tests/ clean
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all
