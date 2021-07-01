/*
** EPITECH PROJECT, 2021
** B-CPE-200-REN-2-1-matchstick-audrey.amar
** File description:
** my_matchstick
*/

#include "../includes/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int more_error(char **tab, char **argv, struct_t *game)
{
    if (game->nb_matches > (game->line*2)-1) {
        my_putstr("Error: not enough matches on this line\n");
        game->turnwerror = 84;
        return 1;
    }
    if (my_error(tab, argv, game) ==  1)
        return 1;
    return 0;
}

int error_matches(char **tab, char **argv, struct_t *game)
{
    if (game->nb_matches == 0 ) {
        my_putstr("Error: you have to remove at least one match\n");
        game->turnwerror = 84;
        return 1;
    } else if (game->nb_matches <= 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        game->turnwerror = 84;
        return 1;
    } else if (more_error(tab, argv, game) == 1)
        return 1;
    return 0;
}

int my_game(char **tab, char **argv, struct_t *game, int res)
{
    while (1) {
        res = didiwin(tab, game->turn);
        if (res == 1 || res == 2)
            return res;
        if (my_turn(tab, argv, game) == 1)
            continue;
        my_putstr("Line: ");
        if (getline(&game->buffer, &game->size, stdin) == -1) {
            my_putchar('\n');
            return 0;
        }if (error_line(argv, game))
            continue;
        my_putstr("Matches: ");
        if (getline(&game->buffer, &game->size, stdin) == -1) {
            my_putchar('\n');
            return 0;
        }
        game->nb_matches = my_getnbr(game->buffer);
        if (error_matches(tab, argv, game) == 1)
            continue;
    }
}

int my_matchstick(char **tab, char **argv, struct_t *game)
{
    int res = didiwin(tab, 0);
    int nbr = my_game(tab, argv, game, res);

    return nbr;
}

int main(int argc, char **argv)
{
    char **tab = NULL;
    int res = 5;
    struct_t *game = malloc(sizeof(struct_t));

    if (argc != 3)
        return 84;
    if (my_getnbr(argv[1]) < 1 || my_getnbr(argv[2]) < 1)
        return 84;
    tab = my_line(my_getnbr(argv[1]), tab);
    res = my_matchstick(tab, argv, game);
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    if (res == 1)
        return 2;
    else if (res == 2)
        return 1;
    else if (res == 0)
        return 0;
}