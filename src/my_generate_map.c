/*
** EPITECH PROJECT, 2021
** B-CPE-200-REN-2-1-matchstick-audrey.amar
** File description:
** generate_map
*/

#include"../includes/my.h"
#include <unistd.h>
#include <stdlib.h>

char *my_space(int nb, char *buf, int *i)
{
    while (nb > 0) {
        buf[*i] = ' ';
        *i = *i + 1;
        nb--;
    }
    return buf;
}

char *my_star(int sb, char *buf, int *i)
{
    static int nb = 1;
    int r = nb;
    int t = sb;

    buf[*i] = 42;
    *i = *i + 1;
    buf = my_space(sb, buf, i);
    while (r > 0) {
        buf[*i] = '|';
        *i = *i + 1;
        r--;
    }
    buf = my_space(t, buf, i);
    buf[*i] = '*';
    *i = *i + 1;
    buf[*i] = '\n';
    *i = *i + 1;
    nb = nb + 2;
    return (buf);
}

void my_top(char *buf, int *i, int p)
{
    while (p > 0) {
        buf[*i] = '*';
        *i = *i + 1;
        p--;
    }
}

char *my_buffer(char *buf, int size, int p, int line)
{
    int i = 0;
    int sb = size - 1;
    int j = line;

    my_top(buf, &i, p);
    buf[i] = 10;
    i++;
    while (j > 0) {
        buf = my_star( sb, buf, &i);
        j--;
        sb--;
    }
    my_top(buf, &i, p);
    buf[i] = '\n';
    i++;
    line = line + 1;
    buf[i] = '\0';
    return buf;
}

char **my_line(int size, char **tab)
{
    int line = size;
    int i = 0;
    int p = (size * 2) + 1;
    int pn = (size + 3) * (p + 2);
    char *buffer = malloc(sizeof(char) * pn);
    buffer = my_buffer(buffer, size, p, line);
    tab = my_malloc(buffer, tab);

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        i++;
    }
    free(buffer);
    return tab;
}
