/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** Function that put every letter of every word in lowercase.
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z')
                    || (str[i] >= '0' && str[i] <= '9'))) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}