/*
** EPITECH PROJECT, 2020
** simple ls
** File description:
** ls
*/

#include "my.h"

void simple_ls(st_t *st, int ac)
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
