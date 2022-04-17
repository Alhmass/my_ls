/*
** EPITECH PROJECT, 2020
** my_ls program.
** File description:
** This program display the element in directory.
*/

#include "../includes/my_ls.h"
#include "../includes/my_printf.h"

int read_directory(char *filepath)
{
    DIR *dir;
    struct dirent *libdata;

    dir = opendir(filepath);
    if (dir == 0) return (84);
    while ((libdata = readdir(dir)) != 0) {
        if (libdata->d_name[0] != '.')
            my_printf("%s ", libdata->d_name);
    }
    closedir(dir);
    return (0);
}

int read_directory_format(char *filepath, int *main_count)
{
    DIR *dir;
    struct dirent *libdata;

    dir = opendir(filepath);
    if (dir == 0 && filepath != NULL) listing_fileformat(filepath);
    if (dir == 0) return (84);
    else if (verif_folder(filepath) == 84) return (84);
    else {
        total_sum(filepath);
        while ((libdata = readdir(dir)) != 0) {
            if (libdata->d_name[0] != '.') {
                listing_format(libdata, filepath);
                my_printf("%s\n", libdata->d_name);
            }
        }
        *main_count = *main_count + 1;
    }
    closedir(dir);
    return (0);
}

void listing_format(struct dirent *libdata, char *filepath)
{
    struct stat statdata;
    struct passwd *userdata;
    struct group *groupdata;
    time_t alltime;
    uid_t user_uid = 0;
    gid_t group_uid = 0;
    char *path = total_path(libdata, filepath);

    stat(path, &statdata);
    alltime = statdata.st_mtime;
    user_uid = statdata.st_uid;
    group_uid = statdata.st_gid;
    userdata = getpwuid(user_uid);
    groupdata = getgrgid(group_uid);
    verif_right(&statdata);
    my_printf("%d ", statdata.st_nlink);
    my_printf("%s ", userdata->pw_name);
    my_printf("%s  ", groupdata->gr_name);
    my_printf("%d ", statdata.st_size);
    date_print(ctime(&alltime));
    free(path);
}

void date_print(char *time)
{
    for (int i = 4; time[i] != '\0'; i++) {
        if (i < 16) my_printf("%c", time[i]);
    }
    my_printf("%c", ' ');
}

int verif_args(char **argv, int *i)
{
    int q = 1;
    char valid_args[] = "l";

    if (my_strlen(argv[*i]) < 2) {
        (*i)++;
        return (84);
    }
    while (my_strchr(valid_args, argv[*i][q]) == 0) {
        q++;
    }
    if (argv[*i][q] != '\0') {
        (*i)++;
        return (84);
    }
    else {
        read_directory_format(argv[*i + 1], i);
        return (0);
    }
}