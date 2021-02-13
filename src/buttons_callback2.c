/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** buttons_callback2.c
*/

#include "hunter.h"

void change_music(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 0) {
        sfSprite_setTexture(scene->buttons[i].sprite,
        scene->buttons[i].texture, sfTrue);
        sfRenderWindow_drawSprite(data->window,
        scene->buttons[i].sprite, NULL);
        sfMusic_setVolume(scene->music->music, 80);
    }
    if (scene->buttons[i].status == 1) {
        sfTexture *texture;

        texture = sfTexture_createFromFile("scene/0/music_off.png", NULL);
        sfSprite_setTexture(scene->buttons[i].sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(data->window, \
        scene->buttons[i].sprite, NULL);
        sfMusic_setVolume(scene->music->music, 0);
    }
}

void change_sound(data_t *data, scene_t *scene, int i)
{
    sfTexture *texture;

    if (scene->buttons[i].status == 0) {
        sfSprite_setTexture(scene->buttons[i].sprite,
        scene->buttons[i].texture, sfTrue);
        sfRenderWindow_drawSprite(data->window,
        scene->buttons[i].sprite, NULL);
    }
    if (scene->buttons[i].status == 1) {
        texture = sfTexture_createFromFile("scene/0/sound_off.png", NULL);
        sfSprite_setTexture(scene->buttons[i].sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(data->window,\
        scene->buttons[i].sprite, NULL);
    }
}

void display_sprite(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status != 3)
        sfRenderWindow_drawSprite(data->window,\
        scene->buttons[i].sprite, NULL);
}

void easy_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        free_current_scene(data, scene);
        data->current_scene = 2;
        new_scene(data, scene);
    } else {
        display_sprite(data, scene, i);
    }
}

void normal_button(data_t *data, scene_t *scene, int i)
{
    if (scene->buttons[i].status == 1) {
        free_current_scene(data, scene);
        data->current_scene = 2;
        new_scene(data, scene);
    } else {
        display_sprite(data, scene, i);
    }
}