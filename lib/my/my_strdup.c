/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *str, int n)
{
    char *src = malloc(sizeof(char) * n);

    for (int i = 0; i < n; i++)
        src[i] = str[i];
    src[n] = '\0';
    return (src);
}