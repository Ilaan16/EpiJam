/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** window.c
*/

#include "hunter.h"

void openwindow(data_t *data)
{
    data->width = 1920;
    data->height = 1080;
    data->bitsPerPixel = 32;
    sfVideoMode mode = {data->width, data->height, data->bitsPerPixel};
    data->window = sfRenderWindow_create(mode, \
    "Hunter", sfDefaultStyle, NULL);
}

void initialise_window(data_t *data)
{
    openwindow(data);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    sfRenderWindow_setMouseCursorVisible(data->window, sfTrue);
}

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        po *= 10;
    }
    return (n);
}

char *my_int_to_char(int nb)
{
    int len = number_digits(nb);
    char *result;

    result = malloc(sizeof(char) * len);
    result[len] = '\0';
    while (len--) {
        result[len] = nb % 10 + '0';
        nb   /= 10;
    }
    return (result);
}