/*
** EPITECH PROJECT, 2018
** Function2
** File description:
** my_functions2.c
*/

#include "./include/my.h"

void get_rights(struct stat info)
{
    my_putstr((S_ISDIR(info.st_mode)) ? "d" : "-");
    my_putstr((info.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((info.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((info.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((info.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((info.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((info.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((info.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((info.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((info.st_mode & S_IXOTH) ? "x" : "-");
    my_putstr(".");
    my_putchar(' ');
}

char *get_date(char *timeinfo, struct stat heure)
{
    for (int i = 8; i != 10; i++) {
        my_putchar(timeinfo[i]);
    }
    my_putchar(' ');
    for (int i = 4; i != 7; i++) {
        my_putchar(timeinfo[i]);
    }
    my_putchar('.');
    for (int i = 10; i != 16; i++) {
        my_putchar(timeinfo[i]);
    }
    my_putchar(' ');
    return (timeinfo);
}

void get_size(struct stat *info)
{
    my_put_nbr(info->st_size);
    my_putchar('\t');
}

void get_nlink(struct stat *info)
{
    my_put_nbr(info->st_nlink);
    my_putchar(' ');
}

void get_name(struct dirent *dir, struct stat *info)
{
    if (!(dir->d_name))
        return ;
    my_putstr(dir->d_name);
    my_putchar(' ');
    my_putchar('\n');
}
