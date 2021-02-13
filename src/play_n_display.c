/*
** EPITECH PROJECT, 2020
** play_n_display.c
** File description:
** play_n_display
*/

#include "hunter.h"

void draw_sprite(data_t *data, scene_t *scene)
{
    if (data->current_scene != 9)
        sfRenderWindow_drawSprite(data->window, \
        scene->background.sprite, NULL);
    for (int i = 0; i < scene->nb_obj; i++)
        sfRenderWindow_drawSprite(data->window, \
        scene->obj[i].sprite, NULL);
    for (int i = 0; i < scene->nb_buttons; i++)
        scene->buttons[i].callback(data, scene, i);
    if (data->current_scene >= 2 && data->current_scene != 9 \
    && data->current_scene != 8) {
        sfRenderWindow_drawSprite(data->window, scene->player.sprite, NULL);
    }
}

void play_sound(scene_t *scene, int y)
{
    sfSound_play(scene->sound[y].sound);
}

void play_music(scene_t *scene, int y)
{
    sfMusic_play(scene->music[y].music);
}

void check_event(sfEvent event, data_t *data, scene_t *scene)
{
    if (event.type == sfEvtKeyPressed\
    && sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue \
    && data->current_scene != 2) {
        free_current_scene(data, scene);
        sfRenderWindow_close(data->window);
    }
}