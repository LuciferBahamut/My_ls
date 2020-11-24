/*
** EPITECH PROJECT, 2020
** display
** File description:
** ls
*/

#include "my.h"

int comp_str(char *stock, char *str)
{
    int nb = my_strlen(stock);
    int nb2 = my_strlen(str);

    if (nb != nb2)
        return (1);
    for (int i = 0; stock[i] != '\0'; i++)
        if (stock[i] != str[i])
            return (1);
    return (0);
}

void display_file(char *stock, st_t *st, char *str)
{
    st->dr = opendir(str);
    while (st->rd = readdir(st->dr))
        if (st->rd->d_type == DT_DIR && comp_str(stock, st->rd->d_name) == 0) {
            display_dir(stock);
            my_putchar('\n');
            break;
        }
        else {
            if (comp_str(stock, st->rd->d_name) == 0) {
                my_putstr(stock);
                my_putchar('\n');
            }
        }
    free(stock);
}
