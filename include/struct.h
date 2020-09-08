/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef enum bool_e {
    false,
    true
} bool_t;

typedef struct shell_s {
    bool_t running;
} shell_t;

typedef struct env_s {
    int *arr;
    char **env;
} env_t;

#endif /* !STRUCT_H_ */
