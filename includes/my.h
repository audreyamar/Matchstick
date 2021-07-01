/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-audrey.amar
** File description:
** my
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct struct_s {
    int line;
    int nb_matches;
    int s;
    char *buffer;
    size_t size;
    int i;
    int turn;
    int turnwerror;
}struct_t;

void my_putchar(char c);

int  my_putstr(char  const *str);

int my_strlen(char const *str);

void my_put_nbr (int nb);

int my_getnbr(char *str);

char **my_malloc(char *buf, char **tab);

char *my_strncpy(char *dest, char const *src, int n);

char **my_line(int size, char **tab);

char **my_ia(char **tab, int turn, char **argv);

void print_exec(int nb_matchstick, int line, int turn);

int howmanyp(char **tab, int line);

char **my_replace_pi(char **tab, int line, int nb_matches);

void  print_game(int line , int nb_matche, char **tab, int turn);

int error_line(char **argv, struct_t *game);

int my_turn(char **tab, char **argv, struct_t *game);

void init_struct(void);

int didiwin(char **tab, int turn);

int my_error(char **tab, char **argv, struct_t *game);
#endif