#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Make file for program infinadd.
#

SRC	=	tests_my_printf_conversion_spec.c \
		tests_my_printf_flag_char.c \
		tests_my_printf_length_modifier.c \
		tests_my_printf_special_cases.c

OBJ = 	$(SRC:.c=.o)

NAME = tests

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L../ -lcriterion --coverage

LDLIBS = -lmy

CPPFLAGS = -I../include

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)


fclean: clean
	rm -f $(NAME)

re: fclean all

cc: re clean

.PHONY: all clean fclean re cc lib
