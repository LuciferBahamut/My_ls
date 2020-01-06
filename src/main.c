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
    struct dirent *read;
    
    if (ac == 1)
        return (0);
    if ((dir = opendir(av[1])) == NULL)
        return(84);
    while (read = readdir(dir))
        my_putchar('\n');
    return (0);
}
