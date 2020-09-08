/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_putstr
*/
#include "proto.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}