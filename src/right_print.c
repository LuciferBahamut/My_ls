/*
** EPITECH PROJECT, 2020
** right
** File description:
** ls
*/

#include "my.h"

char *ct_time(char *time)
{
    char *rslt = malloc(12 * sizeof(char));
    int j = 0;

    for (int i = 4; i != 16; i++, j++)
        rslt[j] = time[i];
    rslt[j] = '\0';
    return (rslt);
}

void print_ugid(uid_t u, gid_t g)
{
    my_putchar(' ');
    my_putstr(getpwuid(u)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(g)->gr_name);
    my_putchar(' ');
}

void right_print(mode_t m)
{
    if (S_ISREG(m))
        my_putchar('-');
    if (S_ISDIR(m))
        my_putchar('d');
    my_putchar((S_IRUSR & m ? 'r' : '-'));
    my_putchar((S_IWUSR & m ? 'w' : '-'));
    my_putchar((S_IXUSR & m ? 'x' : '-'));
    my_putchar((S_IRGRP & m ? 'r' : '-'));
    my_putchar((S_IWGRP & m ? 'w' : '-'));
    my_putchar((S_IXGRP & m ? 'x' : '-'));
    my_putchar((S_IROTH & m ? 'r' : '-'));
    my_putchar((S_IWOTH & m ? 'w' : '-'));
    my_putchar((S_IXOTH & m ? 'x' : '-'));
    my_putchar('.');
    my_putchar(' ');
}
