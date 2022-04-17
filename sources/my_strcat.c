/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** This Function concatenates two strings.
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int x = 0;

    while (dest[x] != '\0') {
        x++;
    }
    while (src[i] != '\0') {
        dest[x] = src[i];
        x++;
        i++;
    }
    return (dest);
}
