/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** my_str_concat.c
*/
#include "proto.h"

char *my_str_concat(char *s, char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(s) + my_strlen(str) + 1));
    int i = 0;

    if (s == NULL && str == NULL)
        return NULL;
    if (s == NULL)
        return str;
    if (str == NULL)
        return s;
    for (; s[i]; i++)
        res[i] = s[i];
    for (int j = 0; str[j]; j++, i++)
        res[i] = str[j];
    res[i] = '\0';
    return res;
}