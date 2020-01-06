/*
** EPITECH PROJECT, 2020
** display directory
** File description:
** ls
*/

#include "my.h"

void display_exe(char *str)
{
    my_putstr(BLUE);
    my_putstr(str);
    my_putstr(WHITE);
}

void display_dir(char *str)
{
    my_putstr(BLUE);
    my_putstr(str);
    my_putstr(WHITE);
}
