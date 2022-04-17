/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Function that display one by one the characters of a string.
*/

#include <unistd.h>
#include "../../includes/my_printf.h"

int my_putstr(char const *str)
{
    int size = my_strlen(str);

    write(1, str, size);
    return (0);
}