/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** game_loop_management.c
*/

#include "hunter.h"

void player_animation(scene_t *scene, data_t *data)
{
    if (data->current_scene != 9) {
        sfSprite_setPosition(scene->player.sprite, scene->player.pos);
        for (int i = 0; i != scene->player.nb_player_text; i++) {
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->clock)) \
            > (i * 100))
                sfSprite_setTexture(scene->player.sprite, \
                scene->player.texture[scene->player.status][i], sfTrue);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(data->clock)) > 350) {
            sfSprite_setTexture(scene->player.sprite, scene->player.texture\
            [scene->player.status][scene->player.nb_player_text - 1], sfTrue);
            sfClock_restart(data->clock);
        }
    }
}

void game_loop(data_t *data, scene_t *scene)
{
    event_management(data, scene);
    sfRenderWindow_clear(data->window, sfBlack);
    draw_sprite(data, scene);
    if (data->current_scene == 0)
        sfRenderWindow_drawText(data->window, data->text.text, NULL);
    sfRenderWindow_display(data->window);
}
