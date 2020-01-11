/*
** EPITECH PROJECT, 2020
** flag t
** File description:
** ls
*/

#include "my.h"

int flag_t_arg(int ac, char **av, st_t *st)
{
    int size = 0;

    for (int i = 2; i != ac; i++) {
        size = my_strlen(av[i]);
        if (size == 2 && av[i][0] == '.' && av[i][1] == '/') {
            my_putstr("./:\n");
            flag_t_simple(st, "./");
            i++;
            if (i != ac)
                my_putchar('\n');
            else
                return (0);
        }
        my_putstr(av[i]);
        my_putstr(":\n");
        flag_t_simple(st, av[i]);
        if (i != ac - 1)
            my_putchar('\n');
    }
    return (0);
}
