/*
** EPITECH PROJECT, 2020
** simple ls
** File description:
** ls
*/

#include "my.h"

int simple_ls_arg(st_t *st, int ac, char **av)
{
    if (ac == 2) {
        if ((st->dr = opendir(av[1])) == NULL)
            return (84);
        simple_ls(st);
    }
    else {
        for (int i = 1; i != ac; i++) {
            if ((st->dr = opendir(av[i])) == NULL)
                return (84);
            my_putstr(av[i]);
            my_putstr(":\n");
            simple_ls(st);
            if (i != ac - 1)
                my_putchar('\n');
        }
    }
}

void simple_ls(st_t *st)
{
    while (st->rd = readdir(st->dr))
        if (st->rd->d_name[0] != '.') {
            if (st->rd->d_type == DT_DIR)
                display_dir(st->rd->d_name);
            else
                my_putstr(st->rd->d_name);
            my_putchar('\n');
        }
}
