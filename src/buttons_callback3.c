/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** buttons_callback3.c
*/

#include "hunter.h"

void loop_pause(data_t *data, scene_t *scene, scene_t *scene2)
{
    while (scene2->buttons[1].status == 1) {
        event_management(data, scene2);
        sfRenderWindow_clear(data->window, sfBlack);
        draw_sprite(data, scene2);
        sfRenderWindow_display(data->window);
    }
}

void how_to(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        free_current_scene(data, scene);
        data->current_scene = 8;
        new_scene(data, scene);
    } else {
        display_sprite(data, scene, i);
    }
}

void leave_how_to(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        free_current_scene(data, scene);
        data->current_scene = 0;
        new_scene(data, scene);
    } else {
        display_sprite(data, scene, i);
    }
}

void loop_inventory(data_t *data, scene_t *scene, scene_t *scene2)
{
    while (scene2->buttons[1].status == 1) {
        event_management(data, scene2);
        sfRenderWindow_clear(data->window, sfBlack);
        draw_sprite(data, scene2);
        sfRenderWindow_display(data->window);
    }
}

void inventory_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        scene_t scene3;
        int last_scene = data->current_scene;
        data->current_scene = 10;
        new_scene(data, &scene3);
        loop_pause(data, scene, &scene3);
        free_current_scene(data, &scene3);
        data->current_scene = last_scene;
    } else {
        display_sprite(data, scene, i);
    }
}