/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** set_ressources.c
*/

#include "hunter.h"

void init_rect_buttons(data_t *data, scene_t *scene, int y)
{
    scene->buttons[y].rect = malloc(sizeof(sfIntRect));
    scene->buttons[y].rect->left = scene->buttons[y].pos.x;
    scene->buttons[y].rect->top = scene->buttons[y].pos.y;
    scene->buttons[y].rect->height = scene->buttons[y].size.y;
    scene->buttons[y].rect->width = scene->buttons[y].size.x;
}

void init_rect_obj(data_t *data, scene_t *scene, int y)
{
    scene->obj[y].rect = malloc(sizeof(sfIntRect));
    scene->obj[y].rect->left = scene->obj[y].pos.x;
    scene->obj[y].rect->top = scene->obj[y].pos.y;
    scene->obj[y].rect->height = scene->obj[y].size.y;
    scene->obj[y].rect->width = scene->obj[y].size.x;
}