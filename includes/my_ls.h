/*
** EPITECH PROJECT, 2020
** my_ls header.
** File description:
** Header file of my_ls program.
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int read_directory(char *filepath);
void listing_format(struct dirent *libdata, char *filepath);
int verif_args(char **argv, int *i);
int read_directory_format(char *filepath, int *main_count);
char *my_strcat(char *dest, char const *src);
void date_print(char *time);
void verif_right(struct stat *statdata);
int total_sum(char *filepath);
char *my_strcpy(char *dest, char const *src);
char *total_path(struct dirent *libdata, char *filepath);
int verif_folder(char *filepath);
void listing_fileformat(char *filepath);