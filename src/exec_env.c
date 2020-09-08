/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** cd.c
*/
#include "proto.h"

void exec_env(char **envp, int *arr)
{
    char n = '\n';

    for (int i = 0; envp[i] != NULL; i++) {
            if (i != arr[i] && arr[i]) {
                write(1, envp[i], my_strlen(envp[i]));
                write(1, &n, 1);
            }
    }
}