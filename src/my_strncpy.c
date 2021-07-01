/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** a function that copies a string into another.
*/

#include"../includes/my.h"
#include <unistd.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int j = 0;

    while (j < n){
        dest[j] = src[j];
        j++;
    }
    while (j > n){
        dest[j] = '\0';
        j++;
    }
    return (dest);
}
