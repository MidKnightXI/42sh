/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_strdup
*/
#include "proto.h"

char *my_strdup(char *str)
{
    int len = 0;
    char *dup = NULL;

    if (str == NULL)
        return "\0";
    len = my_strlen(str);
    dup = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return dup;
}

char *my_strndup(char *str, int size)
{
    int len = 0;
    char *dup = NULL;

    if (str == NULL || len <= size)
        return "\0";
    len = my_strlen(str) - size;
    dup = malloc(sizeof(char) * (len + 1));
    for (int i = size; i <= len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return dup;
}