/*
** EPITECH PROJECT, 2021
** B-CPE-200-REN-2-1-matchstick-audrey.amar
** File description:
** my_change
*/

#include "../includes/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_exec(int nb_matchstick, int line, int turn)
{
    char *p = "Player";
    char *a = "AI";
    char *w;
    if (turn % 2 == 0)
        w = p;
    else
        w = a;
    my_putstr(w);
    my_putstr(" removed ");
    my_put_nbr(nb_matchstick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int howmanyp(char **tab, int line)
{
    int r = 0;
    int i = 0;

    while (tab[line][i] != '\0'){
        if (tab[line][i] == '|')
            r++;
        i++;
    }
    return r;
}

char **my_replace_pi(char **tab, int line, int nb_matches)
{
    int i = 1;

    if (nb_matches > howmanyp(tab, line)) {
        my_putstr("Error: not enough matches on this line \n");
        return tab;
    }
    while (tab[line][i] != '*') {
        i++;
    }i--;
    while (tab[line][i] != '*') {
        if (nb_matches == 0)
            break;
        if (tab[line][i] == '|') {
            tab[line][i] = ' ';
            nb_matches--;
        }
        i--;
    }
    return tab;
}

void  print_game(int line , int nb_matche, char **tab, int turn)
{
    int i = 0;

    tab = my_replace_pi(tab, line, nb_matche);
    print_exec(nb_matche, line, turn);
    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        i++;
    }
}