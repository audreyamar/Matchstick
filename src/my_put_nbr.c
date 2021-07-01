/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** display number
*/
#include "my.h"

void my_putchar(char c);

void my_put_nbr (int nb)
{
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + 48);
    }
    else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    }
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}
