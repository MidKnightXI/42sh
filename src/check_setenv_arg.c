/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** check_setenv_arg
*/
#include "proto.h"

int alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return 0;
}

int num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return 0;
}

int check_name(char *name)
{
    if (alpha(name[0]) == 0) {
        my_put_e("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    for (int i = 1; name[i]; i++) {
        if (num(name[i]) == 0 && alpha(name[i]) == 0) {
            my_put_e("setenv: Variable name must contain ");
            my_put_e("alphanumeric characters.\n");
            return 84;
        }
    }
    return 0;
}