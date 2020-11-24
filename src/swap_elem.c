/*
** EPITECH PROJECT, 2020
** swap elem
** File description:
** ls
*/

#include "my.h"

void swap_elem(int nb, int nb2, char **str)
{
    int size = my_strlen(str[nb]);
    char *temp = malloc((size + 1) * sizeof(char));

    temp = str[nb];
    str[nb] = malloc((my_strlen(str[nb2]) + 1) * sizeof(char));
    str[nb] = str[nb2];
    str[nb2] = malloc((size + 1) * sizeof(char));
    str[nb2] = temp;
}
