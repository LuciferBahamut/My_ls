/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** ls
*/

#include "my.h"

int fs_open_file(char const *file)
{
    int fd = open(file, O_RDONLY);
    struct stat st;

    if (fd == -1)
        return (84);
    stat(file, &st);
    //printf("Name:\t%s\n");
    printf("Type: %d\n", st.st_mode);
    printf("Inode: %d\n", st.st_ino);
    printf("Hard Link: %d\n", st.st_nlink);
    printf("Size: %d\n", st.st_size);
    printf("Allocated space: %d\n", st.st_blocks);
    printf("Minor: %d\n", minor(st.st_dev));
    printf("Major: %d\n", major(st.st_dev));
    printf("UID: %d\n", st.st_uid);
    printf("GID: %d\n", st.st_gid);
    close (fd);
    return (0);
}

int main(int ac, char **av)
{
    fs_open_file(av[1]);
    return (0);
}
