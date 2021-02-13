/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** buttons_callback1.c
*/

#include "hunter.h"

void exit_game(data_t *data, button_t *button, scene_t **s)
{
    if (button->status == 0)
        sfRenderWindow_drawSprite(data->window, button->sprite, NULL);
    if (button->status == 1) {
        sfRenderWindow_close(data->window);
    }
}

void close_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        sfRenderWindow_close(data->window);
    } else {
        display_sprite(data, scene, i);
    }
}

void play_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 2) {
        sfTexture *texture;
        sfSprite *sprite = sfSprite_create();

        texture = sfTexture_createFromFile("scene/0/play_hover.png", NULL);
        sfSprite_setPosition(sprite, scene->buttons[i].pos);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(data->window, sprite, NULL);
    }
    if (scene->buttons[i].status == 1) {
        free_current_scene(data, scene);
        data->current_scene = 1;
        new_scene(data, scene);
    } else if (scene->buttons[i].status != 1 && scene->buttons[i].status != 2)
        display_sprite(data, scene, i);
}

void pause_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        scene_t scene2;
        int last_scene = data->current_scene;
        data->current_scene = 9;
        new_scene(data, &scene2);
        loop_pause(data, scene, &scene2);
        free_current_scene(data, &scene2);
        data->current_scene = last_scene;
    } else {
        display_sprite(data, scene, i);
    }
}

void menu_button(data_t *data, scene_t *scene2, int i)
{
    if (scene2->buttons[i].status == 1) {
        free_current_scene(data, scene2);
        data->current_scene = 0;
        new_scene(data, scene2);
    } else {
        display_sprite(data, scene2, i);
    }
}