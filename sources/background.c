/*
** EPITECH PROJECT, 2020
** Background.
** File description:
** This file contain background script for the main function.
*/

#include "../includes/my_ls.h"
#include "../includes/my_printf.h"

void verif_right(struct stat *statdata)
{
    if (statdata->st_mode & S_IFDIR) my_printf("%c", 'd');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IRUSR) my_printf("%c", 'r');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IWUSR) my_printf("%c", 'w');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IXUSR) my_printf("%c", 'x');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IRGRP) my_printf("%c", 'r');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IWGRP) my_printf("%c", 'w');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IXGRP) my_printf("%c", 'x');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IROTH) my_printf("%c", 'r');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IWOTH) my_printf("%c", 'w');
    else my_printf("%c", '-');
    if (statdata->st_mode & S_IXOTH) my_printf("%c ", 'x');
    else my_printf("%c ", '-');
}

int total_sum(char *filepath)
{
    int total = 0;
    struct stat statdata;
    struct dirent *libdata;
    DIR *dir;
    char *path;

    dir = opendir(filepath);
    if (dir == 0) return (84);
    while ((libdata = readdir(dir)) != 0) {
        if (libdata->d_name[0] != '.') {
            path = total_path(libdata, filepath);
            stat(path, &statdata);
            total = total + statdata.st_blocks;
        }
    }
    my_printf("total %d\n", total / 2);
    free(path);
    closedir(dir);
    return (0);
}

char *total_path(struct dirent *libdata, char *filepath)
{
    int size_filepath = my_strlen(filepath);
    int total_size = size_filepath + my_strlen(libdata->d_name);
    char *path = malloc(sizeof(char) * total_size + 1);

    my_strcpy(path, filepath);
    if (filepath[size_filepath] != '/') {
        path[my_strlen(filepath)] = '/';
        path[size_filepath + 1] = '\0';
    }
    my_strcat(path, libdata->d_name);
    path[total_size + 1] = '\0';
    return (path);
}

int verif_folder(char *filepath)
{
    DIR *dir;
    struct dirent *libdata;

    dir = opendir(filepath);
    if (dir == 0) return (84);
    while ((libdata = readdir(dir)) != 0) {
        if (libdata->d_name[0] != '.') {
            return (0);
        }
    }
    closedir(dir);
    return (84);
}

void listing_fileformat(char *filepath)
{
    struct stat statdata;
    struct passwd *userdata;
    struct group *groupdata;
    time_t alltime;
    uid_t user_uid = 0;
    gid_t group_uid = 0;

    stat(filepath, &statdata);
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
    my_printf("%s", filepath);
}