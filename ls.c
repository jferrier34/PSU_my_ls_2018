/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls.c
*/

#include "./include/my.h"

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

int ls_ac_two(char **argv)
{
    if (argv[1][0] == '-') {
        if ((argv[1][1] == 'l' && argv[1][2] == 't') ||
            (argv[1][1] == 't' && argv[1][2] == 'l'))
            ls_tl();
        if (argv[1][1] == 'l' && argv[1][2] == '\0')
            ls_l();
        if (argv[1][1] == 't' && argv[1][2] == '\0')
            ls_t();
    } else {
        exit (84);
    }
}

int main(int argc, char **argv)
{
    struct dirent *dir;
    DIR *repertory = opendir(".");
    struct dirent *readfiles;
    struct stat info;

    if (argc == 1)
        ls(repertory, readfiles);
    if (argc == 2)
        ls_ac_two(argv);
    if (argc == 3)
        ls_a();
    return (0);
}

