/*
** EPITECH PROJECT, 2020
** octal_converter.
** File description:
** This program convert a number into octal base.
*/

int octal_converter(int nb)
{
    int ret = 0;
    int octal = 0;

    for (int i = 1; nb != 0;) {
        ret = nb % 8;
        octal = ret * i + octal;
        i = i * 10;
        nb = nb / 8;
    }
    return (octal);
}