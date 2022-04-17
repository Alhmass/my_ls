/*
** EPITECH PROJECT, 2020
** display_in_console
** File description:
** This function print the argument send by my_printf to the terminal.
*/

#include <stdarg.h>
#include "../../includes/my_printf.h"

void put_va_int(char *pourcentage, va_list args)
{
    if (pourcentage[0] == 'o') {
        int stock = octal_converter(va_arg(args, int));

        my_put_nbr(stock);
    }
    if (pourcentage[0] == 'X' || pourcentage[0] == 'x') {
        char hex_base[3];
        char *hex_stock = hexa_converter(va_arg(args, int), hex_base);
        if (pourcentage[0] == 'x') {
            hex_stock = my_strlowcase(hex_stock);
        }
        my_putstr(hex_stock);
    } else {
        my_put_nbr(va_arg(args, int));
    }
}

void put_va_char(char *pourcentage, va_list args)
{
    if (pourcentage[0] == 'c') {
        my_putchar(va_arg(args, int));
    } else {
        my_putstr(va_arg(args, char *));
    }
}