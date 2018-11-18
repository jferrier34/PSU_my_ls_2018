/*
** EPITECH PROJECT, 2018
** my_functions.c
** File description:
** my_functions.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb >= 10)
    {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(48 + nb);
    return (0);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int isneg = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        }
        else
            return (nb * isneg);
    }
    return (nb * isneg);

}

int my_strlen(char const *str)
{
    int nbr;

    while (str[nbr] != '\0')
        nbr++;
    return (nbr);
}

int my_charlen(char **str)
{
    int cpt;

    while (str[cpt] != NULL)
        cpt++;
    return (cpt);
}
