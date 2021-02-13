/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** free_scene.c
*/

#include "hunter.h"

void destroy_buttons(data_t *data, scene_t *scene)
{
    for (int i = 0; i != scene->nb_buttons; i++) {
        sfSprite_destroy(scene->buttons[i].sprite);
        sfTexture_destroy(scene->buttons[i].texture);
    }
    free(scene->buttons);
}

void destroy_obj(data_t *data, scene_t *scene)
{
    for (int i = 0; i != scene->nb_obj; i++) {
        sfSprite_destroy(scene->obj[i].sprite);
        sfTexture_destroy(scene->obj[i].texture);
    }
    free(scene->obj);
}

void free_current_scene(data_t *data, scene_t *scene)
{
    if (scene->nb_buttons != 0)
        destroy_buttons(data, scene);
    if (scene->nb_obj != 0)
        destroy_obj(data, scene);
    sfMusic_destroy(scene->music[0].music);
}