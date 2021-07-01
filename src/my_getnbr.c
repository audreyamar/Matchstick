/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** idk
*/

#include"../includes/my.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int j = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            j = j * -1;
        i++;
    }
    while (str[i] != '\0')
        if ((str[i] >= 'A' && str[i] <= 'z') && str[i] != '-')
            return -84;
        else if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        }
        else
            return (nb * j);
    return (nb * j);
}