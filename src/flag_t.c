/*
** EPITECH PROJECT, 2020
** flag_t
** File description:
** ls
*/

#include "my.h"

char **fill_name(char **dis_stock, char **stock, int nb)
{
    int size = 0;
    int j = 0;

    for (int i = 0; i != nb; i++) {
        size = my_strlen(stock[i]);
        dis_stock[i] = malloc((size + 1) * sizeof(char));
        while (stock[i][j] != '/')
            j++;
        j++;
        for (int k = 0; stock[i][j] != '\0'; k++, j++) {
            dis_stock[i][k] = stock[i][j];
            if (stock[i][j + 1] == '\0')
                dis_stock[i][k + 1] = '\0';
        }
        j = 0;
    }
    return (dis_stock);
}

char **fill_stock(int nb, char *str, st_t *st, char **stock)
{
    int size = 0;
    int szdr = my_strlen(str);
    int i = 0;
    int add = 0;

    while ((st->rd = readdir(st->dr)) != 0 || i != nb)
        if (st->rd->d_name[0] != '.') {
            size = my_strlen(st->rd->d_name);
            stock[i] = malloc((size + szdr + 1) * sizeof(char));
            for (int j = 0; str[j] != '\0'; j++)
                stock[i][j] = str[j];
            if (str[szdr - 1] != '/') {
                stock[i][szdr] = '/';
                add++;
            }
            for (int a = szdr + add, b = 0; st->rd->d_name[b] != '\0'; a++, b++)
                stock[i][a] = st->rd->d_name[b];
            i++;
            add = 0;
        }
    return (stock);
}

int count_files(char *str, st_t *st)
{
    int i = 0;

    st->dr = opendir(str);
    while (st->rd = readdir(st->dr))
        if (st->rd->d_name[0] != '.')
            i++;
    closedir(st->dr);
    return (i);
}

void check_time(char **stock, int nb)
{
    int i = 0;
    int tps = 0;
    struct stat st;

    while (i != nb) {
        stat(stock[i], &st);
        tps = st.st_mtime;
        stat(stock[i + 1], &st);
        if (tps < st.st_mtime) {
            swap_elem(i, i + 1, stock);
            i--;
        }
        else
            i++;
    }
}

void flag_t_simple(st_t *st, char *str)
{
    int nb = count_files(str, st);
    char **dis_stock = malloc(nb * (sizeof(char *)));
    char **stock = malloc(nb * (sizeof(char *)));

    st->dr = opendir(str);
    stock = fill_stock(nb, str, st, stock);
    closedir(st->dr);
    if (nb == 1) {
        dis_stock = fill_name(dis_stock, stock, nb);
        display_file(dis_stock[0], st, str);
    }
    else {
        check_time(stock, nb);
        dis_stock = fill_name(dis_stock, stock, nb);
        for (int i = 0; i != nb; i++)
            display_file(dis_stock[i], st, str);
    }
    free(stock);
    free(dis_stock);
}
