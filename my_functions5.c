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

int ls_alpha(char *path)
{
    int cpt = 0;
    int i;
    char **my_tab = malloc(sizeof(char *) * 100);
    struct dirent *readfiles = NULL;
    DIR *repertory = NULL;

    repertory = opendir(path);
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

char *my_strdup(char *b)
{
    char *ret = malloc(my_strlen(b) + 1);
    int i = 0;

    for (; b[i]; i++)
        ret[i] = b[i];
        ret[i] = 0;
    return (ret);
}

int ls_path(char *path)
{
    DIR *repertory = NULL;
    struct dirent *readfiles = NULL;
    struct stat info;
    char **ret = malloc(sizeof(char *) * 256);
    char **s = ret;

    repertory = opendir(path);
    while (readfiles = readdir(repertory)){
        if (readfiles->d_name[0] != '.'){
            *ret = my_strdup(readfiles->d_name);
            ret++;
        }
    }
    *ret = NULL;
    my_sort_word_array(s);
    for (; *s; s++)
        display(readfiles, *s, &info, path);
    return (0);
}

int ls_r(char *path)
{
    int cpt2 = 0;
    int i;
    char **my_tab2 = malloc(sizeof(char *) * 100);
    struct dirent *readfiles = NULL;
    DIR *repertory = NULL;

    repertory = opendir(path);
    while ((readfiles = readdir(repertory))) {
        my_tab2[cpt2] = (char *) malloc(sizeof(readfiles->d_name) + 1);
        my_strcpy(my_tab2[cpt2], readfiles->d_name);
        cpt2 = cpt2 + 1;
    }
    my_sort_word_array(my_tab2);
    for (i = my_charlen(my_tab2) - 1; i > 0; i--) {
        if (my_tab2[i][0] != '.') {
            my_putstr(my_tab2[i]);
            my_putchar('\n');
        }
    }
    closedir (repertory);
}
