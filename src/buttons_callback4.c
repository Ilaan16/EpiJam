/*
** EPITECH PROJECT, 2020
** B-MUL-100-TLS-1-1-myhunter-ilan.chekroun
** File description:
** buttons_callback4.c
*/

#include "hunter.h"

void hard_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        free_current_scene(data, scene);
        data->current_scene = 2;
        new_scene(data, scene);
    } else {
        display_sprite(data, scene, i);
    }
}