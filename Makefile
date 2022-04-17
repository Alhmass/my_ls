#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library making file.
#

SRC	=	sources/main.c \
		sources/my_ls.c \
		sources/my_strcat.c \
		sources/background.c \
		sources/my_strcpy.c


OBJ = 	$(SRC:.c=.o)

NAME = my_ls

LDFLAGS = -L./sources/my_printf/

LDLIBS = -lmy

CPPFLAGS = -I./includes

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	make -C sources/my_printf/

clean:
	make clean -C tests/
	make clean -C sources/my_printf/
	rm -f $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	make fclean -C tests/
	make fclean -C sources/my_printf/
	rm -f $(NAME)

re: fclean all

cc: re clean

unit_tests: CFLAGS += --coverage
unit_tests: fclean all
	make -C tests/

tests_run: unit_tests
	./tests/tests

.PHONY: all clean fclean re cc lib