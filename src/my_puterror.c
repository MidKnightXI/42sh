/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_puterror
*/
#include "proto.h"

void my_put_e(char *str)
{
    write(2, str, my_strlen(str));
}