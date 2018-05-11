/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls.c
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
		for (i = 1; info->st_size % 100 > 40; i++) {
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

/*int get_toto(struct stat *info)
{
    struct dirent *readfiles = NULL;
    DIR *repertory = NULL;
    int cpt1 = 0;
    int cpt2 = 0;
    int cpt3 = 0;
    int cpt4 = 0;
    my_putstr("total: ");
    repertory = opendir(".");
    while (readfiles = readdir(repertory)) {
        if (info->st_size =< 4096)
            cpt1 = cpt1 + 1;
        if (info->st_size > 4096 && info->st_size <= 8096)
            cpt2 = cpt2 + 1;
        if (info->st_size >= )
    }
    }*/

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

void ls_a()
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
    if (argc == 3)
        ls_a();
    return (0);
}
