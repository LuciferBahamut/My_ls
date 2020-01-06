/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my_ls
*/

#ifndef MY_H_
#define MY_H_

#define BLUE "\e[0;34m"
#define WHITE "\e[0;0m"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sysmacros.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putchar(char c);
int my_putstr(char const *str);
void flag_d(int ac, char **av);
void display_dir(char *str);
void simple_ls(DIR *dir, int ac);

#endif
