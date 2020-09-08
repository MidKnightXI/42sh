/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** free_env
*/
#include "proto.h"

void my_envfree(env_t *envi)
{
    int len = tab_len(envi->env) + 1;

    for (int i = 1; i < len; i++)
        free(envi->env[i]);
    free(envi->env);
}

void free_struct(env_t *envi, shell_t *shell)
{
    my_envfree(envi);
    free(envi->arr);
    free(envi);
    free(shell);
}