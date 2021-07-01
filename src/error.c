/*
** EPITECH PROJECT, 2021
** B-CPE-200-REN-2-1-matchstick-audrey.amar
** File description:
** error
*/

#include "../includes/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_norme(char **tab, int *i)
{
    for (int j = 0;  tab[*i][j] != '\0'; j++) {
        if (tab[*i][j] == '|')
            return 0;
    }
    return 1;
}

int my_error(char **tab, char **argv, struct_t *game)
{
    if (game->nb_matches > my_getnbr(argv[2])) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(my_getnbr(argv[2]));
        my_putstr(" matches per turn\n");
        game->turnwerror = 84;
        return 1;
    }
    if (game->nb_matches > howmanyp(tab, game->line)) {
        my_putstr("Error: not enough matches on this line\n");
        game->turnwerror = 84;
        return 1;
    } else {
        print_game(game->line, game->nb_matches, tab, game->turn);
        game->turn++;
    }
    return 0;
}

int didiwin(char **tab, int turn)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_norme(tab, &i) == 0)
            return 0;
    }
    if ((turn % 2) == 1) {
        my_putstr("You lost, too bad...");
        my_putchar('\n');
        return 1;
    }else if ((turn % 2) == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!");
        my_putchar('\n');
        return 2;
    }return 0;
}

int my_turn(char **tab, char **argv, struct_t *game)
{
    if ((game->turn % 2) == 0 && game->turnwerror != 84) {
        my_putchar('\n');
        my_putstr("Your turn:");
        my_putchar('\n');
    }else if ((game->turn % 2) == 1) {
        my_putchar('\n');
        my_putstr("AI's turn...");
        my_putchar('\n');
        my_ia(tab, game->turn, argv);
        game->turn++;
        return 1;
    }return 0;
}

int error_line(char **argv, struct_t *game)
{
    game->line = my_getnbr(game->buffer);
    if (game->line > my_getnbr(argv[1])) {
        my_putstr("Error: this line is out of range\n");
        game->turnwerror = 84;
        return 1;
    }
    if (game->line <= 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        game->turnwerror = 84;
        return 1;
    }return 0;
}
