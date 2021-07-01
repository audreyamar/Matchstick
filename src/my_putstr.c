/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** display characters of a string.
*/

#include <unistd.h>
#include"../includes/my.h"

void my_putchar(char c);

int  my_putstr(char  const *str)
{
    int i;

    i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        ++i;
    }
    return (0);
}
