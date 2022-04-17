/*
** EPITECH PROJECT, 2020
** main function of my_ls.
** File description:
** main
*/

#include "../includes/my_printf.h"
#include "../includes/my_ls.h"

int main(int ac, char **argv)
{
    int i = 1;

    if (ac < 2) argv[i] = ".", ac++;
    else if (ac == 2 && argv[i][0] == '-')
        argv[i + 1] = ".";
    while (i < ac) {
        if (argv[i][0] == '-') {
            verif_args(argv, &i);
        }
        else if (read_directory(argv[i]) == 84) return (84);
        i++;
    }
    return (0);
}