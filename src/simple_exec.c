/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** exec_first.c
*/
#include "proto.h"

void executions(char *bin, char **cmd, char **env)
{
    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 150000000L;

    if (fork() == 0) {
        execve(bin, cmd, env);
        exit(0);
    } else {
        nanosleep(&tim, &tim2);
    }
}

void simple_exec(env_t *envi, char **cmd)
{
    char *tmp = getcwd(NULL, 0);
    char *bin;
    struct stat filestat;

    bin = my_str_concat(tmp, cmd[0]);
    if (!(bin) || stat(cmd[0], &filestat) == -1) {
        my_put_e(cmd[0]);
        my_put_e(": Command not found.\n");
    } else
        executions(bin, cmd, envi->env);
    free(tmp);
    free(bin);
}