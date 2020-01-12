/*
** EPITECH PROJECT, 2020
** strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *res = malloc((my_strlen(dest) + my_strlen(src) + 1) * sizeof(char));

    while (dest[i]) {
        res[i] = dest[i];
        i++;
    }
    if (dest[my_strlen(dest)] != '/') {
        res[my_strlen(dest)] = '/';
        k++;
    }
    while (src[j]) {
        res[i + j + k] = src[j];
        j++;
    }
    res[i + j + k] = '\0';
    return (res);
}
