/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** set_ressources.c
*/

#include "hunter.h"

void set_background(char *file, data_t *data, scene_t *scene)
{
    int i = 0;
    char *filepath = malloc(sizeof(char) * 50);

    filepath = goto_quote2(i, file, filepath);
    init_and_draw_background(filepath, scene, data);
    free(filepath);
}

void set_button(char *file, data_t *data, scene_t *scene, int y)
{
    int i = 0;
    char *filepath = malloc(sizeof(char) * 51);

    filepath = goto_quote2(i, file, filepath);
    i = goto_quote(i, file);
    scene->buttons[y].pos.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].pos.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].size.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].size.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    init_rect_buttons(data, scene, y);
    scene->buttons[y].texture = sfTexture_createFromFile(filepath, NULL);
    init_button(data, scene, y);
    free(filepath);
}

void set_obj(char *file, data_t *data, scene_t *scene, int y)
{
    int i = 0;
    char *filepath = malloc(sizeof(char) * 51);

    filepath = goto_quote2(i, file, filepath);
    i = goto_quote(i, file);
    scene->obj[y].pos.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].pos.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].size.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].size.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].status = my_getnbr(file + i);
    i = goto_coma(i, file);
    init_rect_obj(data, scene, y);
    scene->obj[y].texture = sfTexture_createFromFile(filepath, NULL);
    init_obj(data, scene);
    free(filepath);
}

void set_sound(scene_t *scene, char *file, int y, data_t *data)
{
    char *filepath = malloc(sizeof(char) * 51);

    filepath = goto_quote2(0, file, filepath);
    init_sound(filepath, scene, y);
    data->i_sound++;
    free(filepath);
}

void set_music(scene_t *scene, char *file, int y, data_t *data)
{
    char *filepath = malloc(sizeof(char) * 51);

    filepath = goto_quote2(0, file, filepath);
    init_music(filepath, scene, y);
    data->i_music++;
    free(filepath);
}