/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Display the number given as a argument.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int nb2 = nb;

    if (nb < 0) {
        nb2 = -nb2;
        nb = -nb;
        my_putchar('-');
    }
    if (nb2 > 9) {
        nb2 = my_put_nbr(nb2 / 10);
    }
    nb2 = nb % 10;
    my_putchar(nb2 + 48);
    return (0);
}