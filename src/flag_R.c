/*
** EPITECH PROJECT, 2020
** flag_R
** File description:
** ls
*/

#include "my.h"

int count(st_t *st)
{
    int i = 0;

    while (st->rd = readdir(st->dr))
        if (st->rd->d_name[0] != '.' && st->rd->d_type == DT_DIR)
            i++;
    return (i);
}

char **stock(st_t *st)
{
    char **str;
    int i = count(st);

    st->dr = opendir("./");
    str = malloc((i + 1) * sizeof(char *));
    for (int j = 0, m = 0; st->rd = readdir(st->dr); j++) {
        if (st->rd->d_name[0] != '.' && st->rd->d_type == DT_DIR) {
            str[m] = malloc((my_strlen(st->rd->d_name)+ 1) * sizeof(char));
            str[m] = st->rd->d_name;
            m++;
        }
    }
    return (str);
}

int display(char **str, st_t *st, int i)
{
    for (int j = 0; j != i; j++) {
        my_putstr("\n./");
        my_putstr(str[j]);
        my_putstr(":\n");
        st->dr = opendir(str[j]);
        simple_ls(st);
        closedir(st->dr);
    }
    return (0);
}

void flag_R(st_t *st)
{
    char **str;

    my_putstr(".:\n");
    st->dr = opendir("./");
    simple_ls(st);
    st->dr = opendir("./");
    str = stock(st);
    st->dr = opendir("./");
    display(str, st, count(st));
    free(str);
}
