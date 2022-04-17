/*
** EPITECH PROJECT, 2020
** bsprinfh.
** File description:
** Include .h files of my_printf.
*/

#include <stdarg.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_printf(char *format, ...);
int my_strchr(const char *str, char c);
int check_error(char *check, int *main_count);
void verif_category(char *pourcentage, va_list args);
void my_put_padding(int padding_value);
void put_va_int(char *pourcentage, va_list args);
void put_va_char(char *pourcentage, va_list args);
int octal_converter(int nb);
char *hexa_converter(int nb, char *final_hexa);
char *my_strlowcase(char *str);