/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** exec_cd.c
*/
#include "proto.h"

void alter_cd(char *cmd, char *pwd, env_t *envi)
{
    int i = chdir(cmd);
    struct stat filestat;
    char *str = malloc(sizeof(char) * 1024);

    if (i == -1) {
        if (stat(cmd, &filestat) != -1) {
            my_putstr(cmd);
            my_putstr(": Not a directory.\n");
        } else {
            my_put_e(cmd);
            my_put_e(": No such file or directory.\n");
        }
    } else {
        getcwd(str, 1024);
        my_setenv("OLDPWD", pwd, envi);
        my_setenv("PWD", str, envi);
    }
}

void exec_cd(char **cmd, env_t *envi)
{
    char *home = get_path(envi->env, "HOME=");
    char *oldpwd = get_path(envi->env, "OLDPWD=");
    char *pwd = get_path(envi->env, "PWD=");

    if (cmd[1] == NULL) {
        chdir(home);
        my_setenv("PWD", home, envi);
    } else if (cmd[1][0] == '-' && cmd[1][1] == '\0') {
        chdir(oldpwd);
        my_setenv("OLDPWD", pwd, envi);
        my_setenv("PWD", oldpwd, envi);
    } else
        alter_cd(cmd[1], pwd, envi);
}