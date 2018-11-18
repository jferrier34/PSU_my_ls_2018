/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls.c
*/

#include "./include/my.h"
#include <string.h>

void display(struct dirent *dir, char *repertory, struct stat *info, char *path)
{
    char *display = repertory;
    repertory = path_gen(path, repertory);
    struct stat heure;
    char buff[20];
    char * timeinfo;
    time_t tmp;
    if (lstat(repertory, &heure) == -1)
        return ;
    get_rights(heure);
    timeinfo = ctime(&(heure.st_mtime));
    struct passwd *pwd = getpwuid(heure.st_uid);
    struct group *group = getgrgid(heure.st_gid);
    get_nlink(&heure);
    get_pwd_name(&heure, pwd);
    get_gr_name(&heure, group);
    get_size(&heure);
    get_date(timeinfo, heure);
    my_putstr(display);
    my_putchar(10);
}

void display_simple(struct dirent *dir, char *repertory, struct stat *info)
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

    get_rights(*info);
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
        display_simple(readfiles, readfiles->d_name, &info);
    return (0);
}

int ls_ac_two(char **argv)
{
    if (argv[1][0] == '-') {
        if ((argv[1][1] == 'l' && argv[1][2] == 't') ||
            (argv[1][1] == 't' && argv[1][2] == 'l'))
            ls_tl();
        if (argv[1][1] == 'l' && argv[1][2] == '\0')
            ls_path(argv[2]);
        if (argv[1][1] == 'r' && argv[1][2] == '\0')
            ls_r(argv[2]);
    }
}

int main(int argc, char **argv)
{
    struct dirent *dir;
    DIR *repertory = opendir(".");
    struct dirent *readfiles;
    struct stat info;

    if (argc == 1)
        ls_alpha(".");
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'l')
        ls_l();
    else if (argc == 2 && argv[1][0] != '-')
        ls_alpha(argv[1]);
    else if (argc == 2 && argv [1][0] == '-'
        && argv[1][1] == 'r' && argv[1][2] == '\0')
    ls_r(".");
    if (argc > 2)
        ls_ac_two(argv);
    return (0);
}

