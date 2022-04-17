#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library making file.
#

SRC	=	my_strlen.c \
		my_put_nbr.c \
		my_putstr.c \
		my_printf.c \
		my_strchr.c \
		display_in_console.c \
		octal_converter.c \
		hexa_converter.c \
		my_strlowcase.c

OBJ = 	$(SRC:.c=.o)

NAME = library

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libmy.a

re: fclean all

cc: re clean

.PHONY: all clean fclean re cc lib