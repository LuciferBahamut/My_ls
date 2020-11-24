/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my_ls
*/

#ifndef MY_H_
#define MY_H_

#define BLUE "\x1B[94m"
#define WHITE "\e[0;0m"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct st
{
    DIR *dr;
    struct dirent *rd;
} st_t;

void my_putchar(char c);
int my_putstr(char const *str);
void flag_d(int ac, char **av);
void display_dir(char *str);
void simple_ls(st_t *st);
int simple_ls_arg(st_t *st, int ac, char **av);
int check_flag(int ac, char **av, st_t *st);
void flag_rmaj(st_t *st);
void flag_t_simple(st_t *st, char *str);
int flag_t_arg(int ac, char **av, st_t *st);
int my_strlen(char const *str);
void swap_elem(int nb, int nb2, char **str);
void display_file(char *stock, st_t *st, char *str);
int count_files(char *str, st_t *st);
char *ct_time(char *time);
void print_ugid(uid_t u, gid_t g);
void right_print(mode_t m);
void flag_l(char *str, st_t *st);
int my_put_nbr(int nb);
char *my_strcat(char *dest, char *src);
int multi_l(int ac, char **av, st_t *st);

#endif
