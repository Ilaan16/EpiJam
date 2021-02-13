/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** init_buttons.c
*/

#include "hunter.h"

void init_button(data_t *data, scene_t *scene, int y)
{
    scene->buttons[y].sprite = sfSprite_create();
    sfSprite_setPosition(scene->buttons[y].sprite, scene->buttons[y].pos);
    sfSprite_setTexture(scene->buttons[y].sprite, scene->buttons[y].texture, \
    sfTrue);
    scene->buttons[y].status = 0;
    data->i_buttons++;
}

int boutton_is_pressed(scene_t *s, sfVector2f position, data_t *data, int i)
{
    int y = 0;
    sfVector2f size;
    size.x = s->buttons[i].size.x;
    size.y = s->buttons[i].size.y;
    if (data->mouse.x > position.x && data->mouse.x < position.x + size.x)
        y++;
    if (data->mouse.y > position.y && data->mouse.y < position.y + size.y)
        y++;
    if (y == 2)
        return (1);
    return (0);
}

void buttons_clicked(scene_t *scene, data_t *data)
{
    for (int i = 0; i != scene->nb_buttons; i++) {
        if (boutton_is_pressed(scene, scene->buttons[i].pos, data, i)) {
            if (scene->buttons[i].status == 0 || scene->buttons[i].status == 2)
                scene->buttons[i].status = 1;
            else
                scene->buttons[i].status = 0;
        }
    }
}

void init_button_callback(scene_t *scene, data_t *data)
{
    if (data->current_scene == 0) {
        scene->buttons[0].callback = &play_button;
        scene->buttons[1].callback = &change_music;
        scene->buttons[2].callback = &change_sound;
        scene->buttons[3].callback = &close_button;
        scene->buttons[4].callback = &how_to;
    }
    if (data->current_scene == 1) {
        scene->buttons[0].callback = &easy_button;
        scene->buttons[1].callback = &normal_button;
        scene->buttons[2].callback = &hard_button;
    }
    if (data->current_scene == 2 || data->current_scene == 3) {
        scene->buttons[0].callback = &pause_button;
        scene->buttons[1].callback = &close_button;
        scene->buttons[2].callback = &menu_button;
    }
    if (data->current_scene == 4) {
        scene->buttons[0].callback = &close_button;
    }
    if (data->current_scene == 9) {
        scene->buttons[0].callback = &menu_button;
    }
    if (data->current_scene == 8) {
        scene->buttons[0].callback = &leave_how_to;
    }
}