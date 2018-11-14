/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls.c
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

char *get_date(char *timeinfo, struct stat heure)
{
    for (int i = 9; i != 10; i++) {
        my_putchar(timeinfo[i]);
        my_putchar(' ');
        for (int i = 4; i != 7; i++)
            my_putchar(timeinfo[i]);
            my_putchar('.');
            for (int i = 10; i != 16; i++)
                my_putchar(timeinfo[i]);
                my_putchar(' ');
                }
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
    my_putstr(dir->d_name);
    my_putchar(' ');
    my_putchar('\n');
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

void get_rights(struct stat *info)
{
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
    }

int get_total(struct stat *info)
{
    struct dirent *readfiles = NULL;
    DIR *repertory = NULL;
    int cpt;
    int total = 0;
    my_putstr("total: ");
    repertory = opendir(".");
    while (readfiles = readdir(repertory)) {
        if (readfiles->d_name[0] != '.')
            cpt = stat(readfiles->d_name, info);
            total = total + info->st_size;
    }
    my_put_nbr(total);
    my_putchar('\n');
    closedir(repertory);
    return (total);
}

void display(struct dirent *dir, char *repertory, struct stat *info)
{
    struct stat heure;
    char buff[20];
    char * timeinfo;
    time_t tmp;
    stat(repertory, &heure);
    timeinfo = ctime(&(heure.st_mtime));
    int cpt = stat(repertory, info);
    struct passwd *pwd = getpwuid(info->st_uid);
    struct group *group = getgrgid(info->st_gid);

    get_rights(info);
    get_nlink(info);
    get_pwd_name(info, pwd);
    get_gr_name(info, group);
    get_size(info);
    get_date(timeinfo, heure);
    get_name(dir, info);
}

int ls_l(void)
{
    DIR *repertory = NULL;
    struct dirent *readfiles = NULL;
    struct stat info;

    get_total(&info);
    repertory = opendir(".");
    while (readfiles = readdir(repertory))
    if (readfiles->d_name[0] != '.')
        display(readfiles, readfiles->d_name, &info);

    return (0);
}

void ls(DIR *repertory, struct dirent *readfiles)
{
    repertory = opendir(".");
if (repertory == NULL)
        exit(1);
    while ((readfiles = readdir(repertory)) != NULL) {
        if (readfiles->d_name[0] != '.') {
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
