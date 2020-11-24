/*
** EPITECH PROJECT, 2020
** check_flag
** File description:
** ls
*/

#include "my.h"

int check_flag(int ac, char **av, st_t *st)
{
    if (ac == 2)
        switch (av[1][1]) {
        case 'R' : flag_rmaj(st);
            break;
        case 't' : flag_t_simple(st, "./");
            break;
        case 'l' : flag_l("./", st);
        }
    else
        switch (av[1][1]) {
        case 'd' : flag_d(ac, av);
            break;
        case 't' : flag_t_arg(ac, av, st);
            break;
        case 'l' : multi_l(ac, av, st);
            break;
    }
    return (0);
}
