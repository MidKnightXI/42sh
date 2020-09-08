/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

//includes:

#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"


//lib:

int my_strlen(char *str);
void my_put_e(char *str);
void my_putstr(char *str);
char *my_strdup(char *str);
char *my_strndup(char *str, int size);
char *my_str_concat(char *s, char *str);
char *my_struncat(char *str, char *s);
int my_strcmp(char *cmd, char *str);
int my_strncmp(char *env, char *path, int len);
char **str_warray_path(char const *str);
char **str_warray(char const *str);
char *my_strcpy(char *dest, char const *src);

//proto:

void display_prompt(void);
int get_line(char *name, char **env);
int tab_len(char **str);
char **copy_env(char **envp);
int check_name(char *name);
char *get_path(char **envp, char *src);
char *cleaned_line(char *str);
void free_struct(env_t *envi, shell_t *shell);
void my_envfree(env_t *envi);
void my_unsetenv(char *name, env_t *envi);
void my_setenv(char *name, char *value, env_t *envi);
void exec_env(char **envp, int *arr);
void exec_cd(char **cmd, env_t *envi);
int detect_cmd(env_t *envi, char *c, char **cmd);
void exec_cmd(env_t *envi, char **c);
void simple_exec(env_t *envi, char **cmd);
void my_unsetenv_two(char *name, env_t *e);
void make_array(env_t *e);

void redirections(env_t *envi, char **cmd);
char *find_bin(char **envp, char **c);

#endif
