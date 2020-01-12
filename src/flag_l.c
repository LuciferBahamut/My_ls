/*
** EPITECH PROJECT, 2020
** flag l
** File description:
** ls
*/

#include "my.h"

void display_block(st_t *st, char *str)
{
    struct stat sta;
    char *temp;
    int i = 0;

    st->dr = opendir(str);
    while (st->rd = readdir(st->dr)) {
        temp = my_strcat(str, st->rd->d_name);
        if ((lstat(temp, &sta)) == 0)
            (st->rd->d_name[0] != '.') ? i += sta.st_blocks : 0;
    }
    closedir(st->dr);
    free(temp);
    my_putstr("total ");
    my_put_nbr(i / 2);
    my_putchar('\n');
}

static void display(st_t *st, char *str)
{
    if (st->rd->d_type == DT_DIR)
        display_dir(str);
    else
        my_putstr(str);
    my_putchar('\n');
}

void flag_l(char *str, st_t *st)
{
    struct stat sta;

    display_block(st, str);
    st->dr = opendir(str);
    while ((st->rd = readdir(st->dr)) != 0)
        if (st->rd->d_name[0] != '.') {
            stat(my_strcat(str, st->rd->d_name), &sta);
            right_print(sta.st_mode);
            my_put_nbr(sta.st_nlink);
            print_ugid(sta.st_uid, sta.st_gid);
            my_put_nbr(sta.st_size);
            my_putchar(' ');
            my_putstr(ct_time(ctime(&sta.st_mtime)));
            my_putchar(' ');
            display(st, st->rd->d_name);
        }
}

int multi_l(int ac, char **av, st_t *st)
{
    int size = 0;

    for (int i = 2; i != ac; i++) {
        size = my_strlen(av[i]);
        if (size == 2 && av[i][0] == '.' && av[i][1] == '/') {
            my_putstr("./:\n");
            flag_l("./", st);
            i++;
            if (i != ac)
                my_putchar('\n');
            else
                return (0);
        }
        my_putstr(av[i]);
        my_putstr(":\n");
        flag_l(av[i], st);
        if (i != ac - 1)
            my_putchar('\n');
    }
    return (0);
}
