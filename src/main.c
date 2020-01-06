/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    DIR *dir;

    if (ac == 1) {
        if ((dir = opendir("./")) == NULL)
            return (84);
        simple_ls(dir, ac);
        my_putchar('\n');
    }
    else if (av[1][0] == '-' && av[1][1] == 'd')
        flag_d(ac, av);
    else {
        if ((dir = opendir(av[1])) == NULL)
            return (84);
        simple_ls(dir, ac);
    }
    closedir(dir);
    return (0);
}
