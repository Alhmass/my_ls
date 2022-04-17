/*
** EPITECH PROJECT, 2020
** my_printf function.
** File description:
** This function print in console the call argument.
*/

#include "../../includes/my_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int my_printf(char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && check_error(&format[i], &i) == 0) {
                verif_category(&format[i], args);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return (0);
}

int check_error(char *check, int *main_count)
{
    int count = 1;
    int padding_value = 0;
    char valid_args[] = "dscSiouXx";

    while (check[count] >= '0' && check[count] <= '9') {
        if (count > 0) padding_value = padding_value * 10;
        padding_value = padding_value + (check[count] - 48);
        count++;
    }
    *main_count = *main_count + count;
    if (my_strchr(valid_args, check[count]) == 1) {
        for (int invalid_count = 0; invalid_count != count; invalid_count++) {
            my_putchar(check[invalid_count]);
        }
        return (1);
    }
    my_put_padding(padding_value);
    return (0);
}

void my_put_padding(int padding_value)
{
    if (padding_value == 0) padding_value++;
    while (padding_value != 1) {
        my_putchar(' ');
        padding_value--;
    }
}

void verif_category(char *pourcentage, va_list args)
{
    char valid_int[] = "diouxX";
    char valid_char[] = "csS";

    if (my_strchr(valid_int, pourcentage[0]) == 0) {
        put_va_int(pourcentage, args);
    }
    else if (my_strchr(valid_char, pourcentage[0]) == 0) {
        put_va_char(pourcentage, args);
    }
}