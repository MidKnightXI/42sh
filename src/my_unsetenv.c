/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** my_unsetenv.c
*/

#include "proto.h"

void make_array(env_t *e)
{
    e->arr = malloc(sizeof(int) * 200);

    for (int i = 0; i != 199; i++)
        e->arr[i] = -84;
}

void my_unsetenv_two(char *name, env_t *e)
{
    int line = get_line(name, e->env);

    if (name == NULL) {
        my_put_e("unsetenv: Too few arguments.\n");
    } else if (line == - 1) {
    } else {
        e->arr[line] = line;
    }
}