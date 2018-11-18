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

int ls_tl(void)
{
    my_putstr("o");
    return 0;
}

int my_putstr(char *str)
{
    int nbr = 0;
    int a = 0;

    while (str[nbr] != '\0') {
        nbr++;
    }
    while (a < nbr) {
        my_putchar(str[a]);
        a++;
    }
}

char *path_gen(char *a, char *b)
{
    char *ret = malloc(my_strlen(a) + my_strlen(b) + 3);
    char *s = ret;
    for (; *a; a++){
        *ret = *a;
        ret++;
    }
    if (*(ret - 1) != '/'){
        *ret = '/';
        ret++;
    }
    for (; *b; b++){
        *ret = *b;
        ret++;
    }
    *ret = 0;
    return (s);
}
