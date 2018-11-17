/*
** EPITECH PROJECT, 2018
** my_functions5.c
** File description:
** my_functions5.c
*/

#include "./include/my.h"

void funct(struct stat *info, int *total)
{
    struct dirent *readfiles = NULL;
    int len;
    int cpt;
    int i = 1;

    if (info->st_size < 1000)
                *total = *total + 4;
            else {
                for (i; info->st_size  > 4096; i++) {
                    info->st_size = info->st_size - 4096;
                }
                *total = *total + (4 * i);
                }
}

int ls_alpha(void)
{
    int cpt = 0;
    int i;
    char **my_tab = malloc(sizeof(char *) * 100);
    struct dirent *readfiles = NULL;
    DIR *repertory = NULL;

    repertory = opendir(".");
    while ((readfiles = readdir(repertory))) {
        my_tab[cpt] = (char *) malloc(sizeof(readfiles->d_name) + 1);
        my_strcpy(my_tab[cpt++], readfiles->d_name);
    }
    my_sort_word_array(my_tab);
    for (i = 0; i < cpt; i++) {
        if (my_tab[i][0] != '.') {
            my_putstr(my_tab[i]);
            my_putchar('\n');
        }
    }
    closedir (repertory);
    return (0);
}
