/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** copy_env
*/
#include "proto.h"

char **copy_env(char **envp)
{
    char **copy = NULL;
    int len = tab_len(envp);

    copy = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i < len; i++)
        copy[i] = my_strdup(envp[i]);
    copy[len] = NULL;
    return copy;
}