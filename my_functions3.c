/*
** EPITECH PROJECT, 2018
** Function3
** File description:
** my_functions3.c
*/

#include "./include/my.h"

int get_total(struct stat *info)
{
    struct dirent *readfiles = NULL;
    DIR *repertory = NULL;
    int cpt;
    int total = 0;
    int len;
    int i = 1;
    my_putstr("total: ");
    repertory = opendir(".");
    while (readfiles = readdir(repertory)) {
        if (readfiles->d_name[0] != '.') {
            len = my_strlen(readfiles->d_name);
            readfiles->d_name[len + 1] = '\0';
            cpt = stat(readfiles->d_name, info);
            if (info->st_size < 1000)
                total = total + 4;
            else {
                for (i = 1; info->st_size  > 4096; i++) {
                    info->st_size = info->st_size - 4096;
                }
                total = total + (4 * i);
            }
        }
    }
    my_put_nbr(total);
    my_putchar('\n');
    closedir(repertory);
    return (total);
}

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
