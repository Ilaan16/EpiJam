/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** init.c
*/

#include "hunter.h"

void init_time_n_clock(data_t *data, scene_t *scene)
{
    data->clock = sfClock_create();
    scene->player.move_player_clock = sfClock_create();
    scene->player.move_player_time;
    data->time;
    float seconds;
}

void init_music(char *filepath, scene_t *scene, int y)
{
    scene->music[y].music = sfMusic_createFromFile(filepath);
    scene->music[y].volume = 50;
    sfMusic_setVolume(scene->music[y].music, scene->music[y].volume);
    sfMusic_play(scene->music[y].music);
}

void init_sound(char *filepath, scene_t *scene, int y)
{
    scene->sound[y].soundbuffer = sfSoundBuffer_createFromFile(filepath);
    scene->sound[y].sound = sfSound_create();
    sfSound_setBuffer(scene->sound[y].sound, scene->sound[y].soundbuffer);
}

void buttons_hover(scene_t *scene, data_t *data)
{
    if (boutton_is_pressed(scene, scene->buttons[0].pos, data, 0)) {
        scene->buttons[0].status = 2;
    } else
        scene->buttons[0].status = 0;
}

void init_obj(data_t *data, scene_t *scene)
{
    scene->obj[data->i_obj].sprite = sfSprite_create();
    sfSprite_setPosition(scene->obj[data->i_obj].sprite, \
    scene->obj[data->i_obj].pos);
    sfSprite_setTexture(scene->obj[data->i_obj].sprite, \
    scene->obj[data->i_obj].texture, sfTrue);
    if (data->current_scene != 1 && data->current_scene != 8)
        sfSprite_scale(scene->obj[data->i_obj].sprite, (sfVector2f){0.5, 0.5});
    data->i_obj++;
}
