/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void my_putchar(char c);
int my_putstr(char *str);
int  my_put_nbr(int nb);
int my_getnbr(char const *str);
void get_rights(struct stat *info);
char *get_date(char *timeinfo, struct stat heure);
void get_size(struct stat *info);
void get_nlink(struct stat *info);
void get_name(struct dirent *dir, struct stat *info);
void get_pwd_name(struct stat *info, struct passwd *pwd);
void get_gr_name(struct stat *info, struct group *group);
int my_strlen(char const *str);
#endif

