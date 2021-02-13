/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** file_parsing.c
*/

#include "hunter.h"

int open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    free(filepath);
    return (fd);
}

int goto_coma(int i, char *file)
{
    while (file[i] != ',')
        i++;
    i++;
    return (i);
}

char *goto_quote2(int i, char *file, char *filepath)
{
    int y = 0;

    while (file[i] != 34)
        i++;
    i++;
    while (file[i] != 34) {
        filepath[y] = file[i];
        i++;
        y++;
    }
    filepath[y] = '\0';
    return (filepath);
}

int goto_quote(int i, char *file)
{
    while (file[i] != 34)
        i++;
    i++;
    while (file[i] != 34) {
        i++;
    }
    i++;
    return (i);
}