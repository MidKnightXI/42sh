/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** exec_cmd.c
*/
#include "proto.h"

char *find_bin(char **envp, char **c)
{
    char *path = get_path(envp, "PATH");
    char **divided_paths = str_warray_path(path);
    char *cmd = my_str_concat("/", c[0]);
    char *str;
    struct stat filestat;

    for (int i = 0; divided_paths[i] != NULL; i++) {
        str = my_str_concat(divided_paths[i], cmd);
        if (stat(str, &filestat) != -1) {
            free(cmd);
            free(divided_paths);
            free(path);
            return str;
        }
    }
    free(cmd);
    free(divided_paths);
    free(path);
    free(str);
    return NULL;
}

void execution(char *bin, char **cmd, char **env)
{
    if (fork() == 0) {
        execve(bin, cmd, env);
        exit(0);
    } else {
    }
}

void exec_cmd(env_t *envi, char **cmd)
{
    char *bin = find_bin(envi->env, cmd);
    struct stat filestat;

    if (stat(cmd[0], &filestat) != -1) {
        if (fork() == 0) {
            execve(cmd[0], cmd, envi->env);
            exit(0);
        }
    } else if (!(bin)) {
        my_put_e(cmd[0]);
        my_put_e(": Command not found.\n");
    } else {
        execution(bin, cmd, envi->env);
    }
    free(bin);
}