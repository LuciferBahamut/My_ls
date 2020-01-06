/*
** EPITECH PROJECT, 2020
** simple ls
** File description:
** ls
*/

#include "my.h"

void simple_ls(DIR *dir, int ac)
{
    struct dirent *read;

    if (ac == 1) {
        while (read = readdir(dir))
            if (read->d_name[0] != '.') {
                if (read->d_type == DT_DIR)
                    display_dir(read->d_name);
                else
                    my_putstr(read->d_name);
                my_putchar(' ');
            }
    }
    else {
        while (read = readdir(dir))
            if (read->d_name[0] != '.') {
                if (read->d_type == DT_DIR)
                    display_dir(read->d_name);
                else 
                    my_putstr(read->d_name);
                my_putchar('\n');
            }
    }
}
