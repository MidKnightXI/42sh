/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** unsetenv
*/
#include "proto.h"

void my_envdeleter(env_t *envi, char **tmp, int line)
{
    int len = tab_len(tmp);

    envi->env = malloc(sizeof(char *) * (len - 1));
    for (int i = 0; i < len; i++) {
        if (i == line);
        else
            envi->env[i] = my_strdup(tmp[i]);
    }
    envi->env[len - 2] = NULL;
}

void my_unsetenv(char *name, env_t *envi)
{
    char **tmp = copy_env(envi->env);
    int line = get_line(name, tmp);

    if (name == NULL)
        my_put_e("unsetenv: Too few arguments.\n");
    else if (line == -1) {
        my_put_e("The *");
        my_put_e(name);
        my_put_e("* variable does not exist\n");
    } else {
        my_envfree(envi);
        my_envdeleter(envi, tmp, line);
    }
    free(tmp);
    free(name);
}