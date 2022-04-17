/*
** EPITECH PROJECT, 2020
** hexa_converter.
** File description:
** This program convert decimal to hexadecimal.
*/

char *hexa_converter(int nb, char *final_hexa)
{
    int ret = 0;
    int letter_value = 0;

    for (int i = 1; nb >= 10;) {
        ret = nb % 16;
        letter_value = ret * i + letter_value;
        i = i * 10;
        nb = nb / 16;
    }
    final_hexa[0] = nb + 48;
    if (letter_value >= 10) {
        final_hexa[1] = letter_value + 55;
    } else {
        final_hexa[1] = letter_value + 48;
    }
    return (final_hexa);
}