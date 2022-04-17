/*
** EPITECH PROJECT, 2020
** my strchr
** File description:
** function return pointer to the first occurence.
*/

#include <stddef.h>

int my_strchr(const char *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c) {
            return (0);
        }
        i++;
    }
    return (1);
}