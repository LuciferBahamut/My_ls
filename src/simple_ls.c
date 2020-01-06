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

    while (read = readdir(dir))
        if (read->d_name[0] != '.') {
            if (read->d_type == DT_DIR)
                display_dir(read->d_name);
                //else if (read->d_type == DT_LNK)
                //    display_exe(read->d_name);
            else
                my_putstr(read->d_name);
            my_putchar('\n');
        }
}
