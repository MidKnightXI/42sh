/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_strlen
*/
#include "proto.h"

int my_strlen(char *str)
{
    int len = 0;

    if (str == NULL)
        return 0;
    for (; str[len]; len++);
    return len;
}