/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** setenv
*/
#include "proto.h"

int get_line(char *name, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 1)
            return i;
    }
    return -1;
}

void my_envrealloc(env_t *envi, char **tmp, char *name)
{
    int len = tab_len(tmp);

    envi->env = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; i < len; i++)
        envi->env[i] = my_strdup(tmp[i]);
    envi->env[len] = my_strdup(name);
    envi->env[len + 1] = NULL;
}

void my_envalloc(env_t *envi, char *name, int line)
{
    free(envi->env[line]);
    envi->env[line] = malloc(sizeof(char) * (my_strlen(name) + 1));
    envi->env[line] = my_strdup(name);
}

void exec_setenv(char *name, char *value, env_t *envi)
{
    char **tmp = copy_env(envi->env);
    int line = get_line(name, tmp);

    if (line == -1) {
        name = my_str_concat(name, "=");
        name = my_str_concat(name, value);
        my_envfree(envi);
        my_envrealloc(envi, tmp, name);
    } else {
        name = my_str_concat(name, "=");
        name = my_str_concat(name, value);
        my_envalloc(envi, name, line);
    }
    envi->arr[line] = -84;
    free(tmp);
}

void my_setenv(char *name, char *value, env_t *envi)
{
    if (name == NULL)
        exec_env(envi->env, envi->arr);
    else if (check_name(name) == 84);
    else
        exec_setenv(name, value, envi);
    free(value);
}