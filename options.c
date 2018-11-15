/*
** EPITECH PROJECT, 2018
** options.c
** File description:
** list options functions
*/

#include "./include/my.h"

void ls_a(void)
{
    DIR *repertory = NULL;
    struct dirent *readfiles;
    repertory = opendir(".");

    if (repertory != NULL) {
        while ((readfiles = readdir(repertory))) {
            if (readfiles->d_name[2] != '.') {
                my_putstr(readfiles->d_name);
                my_putstr("\t");
            }
        }
        closedir(repertory);
    }
}

int ls_t(void)
{
    my_putchar ('t');
    return 0;
}

int ls_tl(void)
{
    my_putstr("tl");
    return 0;
}

