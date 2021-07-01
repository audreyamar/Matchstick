/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** count how many char there are in the string.
*/

#include"../includes/my.h"

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0'){
        n++;
    }
    return (n);
}
