/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** str_warray_path.c
*/
#include <stdlib.h>

int detect_point(char c)
{
    if ((c >= 33 && c < ':') || c > ':')
        return 1;
    else
        return 0;
}

int number_words(char const *str)
{
    int i = 0;
    int words = 0;

    while (str[i] != '\0') {
        if (detect_point(str[i]) == 1)
            words++;
        for (; detect_point(str[i]) == 1 && str[i] != '\0'; i++);
        if (str[i] != '\0')
            i++;
    }
    return words;
}

int lengh_words(char const *str, int j)
{
    int len = 0;

    for (; detect_point(str[j]) == 1; j++, len++);
    return len;
}

char **str_warray_path(char const *str)
{
    char **array = malloc(sizeof(char *) * (number_words(str) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; i != number_words(str); i++) {
        k = 0;
        for (; detect_point(str[j]) == 0; j++);
        array[i] = malloc(sizeof(char) * (lengh_words(str, j) + 1));
        for (; detect_point(str[j]) == 1; k++, j++)
            array[i][k] = str[j];
        array[i][k] = '\0';
    }
    array[i] = NULL;
    return array;
}