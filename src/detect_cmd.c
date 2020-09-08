/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** cmd_detect
*/
#include "proto.h"

int detect_unbuildin(char *c, char **cmd)
{
    if (my_strcmp(c, "cd") == 1)
        return 1;
    if (my_strcmp(c, "env") == 1)
        return 2;
    if (my_strcmp(c, "setenv") == 1)
        return 3;
    if (my_strcmp(c, "unsetenv") == 1)
        return 4;
    for (int k = 0; cmd[k]; k++)
        if (cmd[k][0] == '<' || cmd[k][0] == '>')
            return 5;
    return 6;
}

int detect_cmd(env_t *envi, char *c, char **cmd)
{
    int i = detect_unbuildin(c, cmd);

    if (i == 1)
        exec_cd(cmd, envi);
    if (i == 2)
        exec_env(envi->env, envi->arr);
    if (i == 3)
        my_setenv(cmd[1], cmd[2], envi);
    if (i == 4)
        my_unsetenv_two(cmd[1], envi);
    if (i == 5)
        redirections(envi, cmd);
    if (i == 6)
        return -1;
    return 0;
}