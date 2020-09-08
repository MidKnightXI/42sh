/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** cmd
*/

#include "proto.h"

void close_file(int fd, int fd0)
{
    close(fd);
    dup2(fd0, 1);
    close(fd0);
}

void exec_redir(env_t *envi, char **cmd, int rd, int rd0)
{
    char **arg = malloc(sizeof(char *) *30);
    char *bin = find_bin(envi->env, cmd);

    for (int k = 0; k < 30; k++)
        arg[k] = malloc(sizeof(char) * 100);
    for (int m = 0; cmd[m]; m++) {
        for (int t = 0; cmd[m][t] != '\0'; t++) {
            arg[m][t] = cmd[m][t];
            arg[m][t+1] = '\0';
        }
    }
    arg[rd][0] = '\0';
    if (rd0 != 0)
        arg[rd0][0] = '\0';
    if (!(bin)) {
        my_put_e(cmd[0]);
        my_put_e(": Command not found.\n");
        exit(0);
    }
    execve(bin, arg, envi->env);
}

int open_file(char **cmd, char *file, int fd, int k)
{
    if (cmd[k][0] == '>') {
        fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR |
        S_IRGRP | S_IWGRP | S_IWUSR);
        dup2(fd, 1);
        close(fd);
    } else {
        fd = open(file, O_WRONLY);
        if (fd == -1) {
            my_putstr(file);
            my_putstr(": No such file or directory.\n");
            exit(0);
        }
    }
    return fd;
}

void redirections(env_t *envi, char **cmd)
{
    int fd = 0;
    int fd0 = 0;
    int k = 0;
    int rd = 0;
    int rd0 = 0;
    char *file = malloc(sizeof(char) * 100);

    for (; cmd[k][0] != '<' && cmd[k][0] != '>'; k++)
        rd = k + 1;
    if (my_strlen(cmd[k]) == 1) {
        file = my_strcpy(file, cmd[k + 1]);
        rd0 = rd + 1;
    } else
        for (int m = 1; cmd[k][m] != '\0'; m++)
            file[m-1] = cmd[k][m];
    if (fork() == 0) {
        fd0 = dup(1);
        fd = open_file(cmd, file, fd, k);
        exec_redir(envi, cmd, rd, rd0);
        close_file(fd, fd0);
    }
}