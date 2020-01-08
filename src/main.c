/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    st_t *st = malloc(3);

    if (ac == 1) {
        if ((st->dr = opendir("./")) == NULL)
            return (84);
        simple_ls(st, ac);
        closedir(st->dr);
    }
    else if (av[1][0] == '-')
        check_flag(ac, av);
    else {
        if ((st->dr = opendir(av[1])) == NULL)
            return (84);
        simple_ls(st, ac);
        closedir(st->dr);
    }
    free(st);
    return (0);
}
