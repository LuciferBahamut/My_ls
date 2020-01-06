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
        display_dir(av[2]);
        my_putchar('\n');
    }
}
