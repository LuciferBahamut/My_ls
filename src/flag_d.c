/*
** EPITECH PROJECT, 2020
** flag_d
** File description:
** my_ls
*/

#include "my.h"

void flag_d(int ac, char **av)
{
    if (ac == 2)
        display_dir(".\n");
    else {
        for (int i = 2; i != ac; i++) {
            if (i == ac - 1) {
                display_dir(av[i]);
                my_putchar('\n');
            }
            else {
                display_dir(av[i]);
                my_putchar(' ');
            }
        }
    }
}
