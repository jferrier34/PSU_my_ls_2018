/*
** EPITECH PROJECT, 2018
** Function3
** File description:
** my_functions3.c
*/

#include "./include/my.h"

void get_pwd_name(struct stat *info, struct passwd *pwd)
{
    my_putstr(pwd->pw_name);
    my_putchar(' ');
}

void get_gr_name(struct stat *info, struct group *group)
{
    my_putstr(group->gr_name);
    my_putchar('\t');
}
