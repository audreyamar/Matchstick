/*
** EPITECH PROJECT, 2021
** B-CPE-200-REN-2-1-matchstick-audrey.amar
** File description:
** my_ia
*/

#include"../includes/my.h"
#include <unistd.h>
#include <stdlib.h>

int searchp(char **tab, int line, char **argv)
{
    int p = 0;

    for (int j = 0;  tab[line][j] != '\0'; j++) {
        if (tab[line][j] == '|')
            p++;
    }
    if (p > my_getnbr(argv[2]))
        return my_getnbr(argv[2]);
    else
        return p;
}

char **my_ia(char **tab, int turn, char **argv)
{
    int line = rand() % (my_getnbr(argv[1]) + 1);
    int nb_matches = rand () % my_getnbr(argv[2]);
    int p = 0;

    if (line == 0)
        line++;
    if (nb_matches == 0)
        nb_matches++;
    p = searchp(tab, line, argv);
    while (p == 0 || p < nb_matches) {
        line = rand() % (my_getnbr(argv[1]) + 1);
        p = searchp(tab, line, argv);
        nb_matches = p;
    }
    print_game(line, nb_matches, tab, turn);
    return tab;
}
