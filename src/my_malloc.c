/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-audrey.amar
** File description:
** my_malloc
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include"../includes/my.h"

int line(char c)
{
    if (c <= '\n')
        return 0;
    return 1;
}

int nbword(char *str)
{
    int i = 0;
    int counter = 0;

    while (str != NULL && str[i]){
        if (line(str[i]) == 1 && line(str[i + 1]) == 0)
            counter = counter + 1;
        i++;
    }
    return counter;
}

char **my_malloc(char *buf, char **tab)
{
    int j = 0;
    int i = 0;
    char *str = buf;
    tab = malloc((nbword(str) + 2) * sizeof(char *));
    int len = 0;

    while (str != NULL && str[i]){
        if (line(str[i]))
            len = len + 1;
        if (line(str[i]) == 1 && line(str[i + 1]) == 0){
            tab[j] = malloc(len + 2);
            my_strncpy(tab[j], &str[i - len + 1], len);
            tab[j][len] = '\n';
            tab[j][len + 1] = '\0';
            len = 0;
            j++;
        }i++;
    }
    tab[j] = NULL;
    return tab;
}
