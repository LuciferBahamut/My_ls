/*
** EPITECH PROJECT, 2020
** check_flag
** File description:
** ls
*/

#include "my.h"

int check_flag(int ac, char **av)
{
    switch(av[1][1]) {
    case 'd' : flag_d(ac, av);
        break;
    }
    return (0);
}
