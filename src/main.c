/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** main.c
*/
#include "proto.h"

void sigint_handler(int signum)
{
    signal(SIGINT, sigint_handler);
    my_putstr("\b\b  \n");
    display_prompt();
}

void sigsegv_handler(int sig_num)
{
    signal(SIGINT, sigint_handler);
    my_putstr("Segmentation fault (core dumped)\n");
    display_prompt();
}

void sigfpe_handler(int sig)
{
    signal(SIGFPE, sigfpe_handler);
    my_putstr("Floating exception (core dumped)\n");
    display_prompt();
}

int my_shell(env_t *envi)
{
    size_t bufsize = 32;
    char *c = malloc(sizeof(char) * bufsize);
    char **cmd;

    if (getline(&c, &bufsize, stdin) == -1 || my_strcmp(c, "exit\n") == 1) {
        if (isatty(0) == 1)
            my_putstr("exit\n");
        return 1;
    }
    if (my_strncmp(c, "\n", 1) == 1)
        return 0;
    cmd = str_warray(c);
    if (my_strncmp(cmd[0], "./", 2) == 1) {
        cmd[0] = my_struncat(cmd[0], ".");
        simple_exec(envi, cmd);
    } else if (detect_cmd(envi, cmd[0], cmd) == -1)
        exec_cmd(envi, cmd);
    free(c);
    free(cmd);
    return 0;
}

int main(int ac, char **av, char **envp)
{
    shell_t *shell = malloc(sizeof(shell_t));
    env_t *envi = malloc(sizeof(env_t));
    shell->running = true;

    (void)av;
    envi->env = copy_env(envp);
    make_array(envi);
    if (ac > 1)
        return 84;
    signal(SIGSEGV, sigsegv_handler);
    signal(SIGINT, sigint_handler);
    signal(SIGFPE, sigfpe_handler);
    while (shell->running == true) {
        display_prompt();
        if (my_shell(envi) == 1)
            break;
    }
    free_struct(envi, shell);
    return 0;
}