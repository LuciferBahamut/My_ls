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
        simple_ls(st);
        closedir(st->dr);
    }
    else if (av[1][0] == '-')
        check_flag(ac, av, st);
    else {
        if (simple_ls_arg(st, ac, av) == 84)
            return (84);
        closedir(st->dr);
        }
    free(st);
    return (0);
}
