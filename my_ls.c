/*
** EPITECH PROJECT, 2018
** info.c
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "./include/my.h"

#define couleur(param) fprintf(stderr, "\b \033[%sm", param)

void display(struct dirent *dir, char *repertory, struct stat *info)
{
    int cpt = stat(repertory, info);
    struct passwd *pwd = getpwuid(info->st_uid);
    struct group *group = getgrgid(info->st_gid);

    my_putstr((S_ISDIR(info->st_mode)) ? "d" : "-");
    my_putstr((info->st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((info->st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((info->st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((info->st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((info->st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((info->st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((info->st_mode & S_IROTH) ? "r" : "-");
    my_putstr((info->st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((info->st_mode & S_IXOTH) ? "x" : "-");
    my_putstr(".");
    my_putchar(' ');
    my_put_nbr(info->st_nlink);
    my_putchar(' ');
    my_putstr(pwd->pw_name);
    my_putchar(' ');
    my_putstr(group->gr_name);
    my_putchar(' ');
    my_put_nbr(info->st_size);
    my_putchar(' ');
    my_putstr(dir->d_name);
    my_putchar(' ');
    my_putchar('\n');
}

int ls_l(void)
{
    DIR *repertory = NULL;
    struct dirent *readfiles = NULL;
    struct stat info;

    repertory = opendir(".");
    while (readfiles = readdir(repertory))
    if (readfiles->d_name[0] != '.')
        display(readfiles, readfiles->d_name,&info);
    return (0);
}

void ls(DIR *repertory, struct dirent *readfiles)
{
    repertory = opendir(".");
if(repertory == NULL)
        exit(1);
    while ((readfiles = readdir(repertory)) != NULL) {
        if(readfiles->d_name[0] != '.') {
            my_putstr(readfiles->d_name);
            my_putchar(' ');
            my_putchar('\n');
        }
    }
    if (closedir(repertory) == - 1)
        exit(84);
}

int main(int argc, char *argv[])
{
    struct dirent *dir;
    DIR *repertory = opendir(".");
    struct dirent *readfiles;
    struct stat info;

    if (argc == 1)
        ls(repertory, readfiles);
    if (argc == 2)
        ls_l();
    return (0);
}
