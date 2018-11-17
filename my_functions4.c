/*
** EPITECH PROJECT, 2018
** my_functions4.c
** File description:
** my_functions4
*/

#include "./include/my.h"

int abkqs(char a, char b)
{
    a -= ((a >= 97) * 32);
    b -= ((b >= 97) * 32);
    if (a < b)
        return (-1);
    if (a > b)
        return (1);
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (i; i < my_strlen(s1); i++) {
        if (abkqs(s1[i], s2[i]) == -1)
            return (-1);
        else if (abkqs(s1[i], s2[i]) == 1)
            return (1);
    }
    return (0);
}

void swapping(char **array, int i)
{
    char *save = array[i - 1];
    array[i - 1] = array[i];
    array[i] = save;
}

int sorting(char **array)
{
    for (int i = 1; array[i]; i++){
        if (my_strcmp(array[i - 1],  array[i]) > 0){
            swapping(array, i);
            return (0);
        }
    }
    return (1);
}

void my_sort_word_array(char **array)
{
    while (sorting(array) == 0);
}

