/*
** EPITECH PROJECT, 2020
** Run_For_Live
** File description:
** scene.c
*/

#include "hunter.h"

void init_data(data_t *data)
{
    data->i_buttons = 0;
    data->i_obj = 0;
    data->i_sound = 0;
    data->i_music = 0;
    data->life = 3;
    data->score = 0;
    data->speed = 5;
}

void init_scene(scene_t *scene, data_t *data)
{
    get_nb_buttons(scene, data);
    get_nb_obj(scene, data);
    get_nb_music(scene, data);
    get_nb_sound(scene, data);
    get_nb_player_text(scene, data);
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons);
    scene->obj = malloc(sizeof(obj_t) * scene->nb_obj);
    scene->sound = malloc(sizeof(sound_t) * scene->nb_sound);
    scene->music = malloc(sizeof(music_t) * scene->nb_music);
    scene->player.status = 0;
    scene->player.i_texture[scene->player.status] = 0;
    scene->player.texture = malloc(sizeof(sfTexture **) * 4);
    for (int i = 0; i != 4; i++) {
        scene->player.texture[i] = malloc(sizeof(sfTexture *) \
        * scene->player.nb_player_text);
        scene->player.i_texture[i] = 0;
    }
}

char *get_scene_filepath(data_t *data)
{
    char *filepath = malloc(sizeof(char) * 20);
    filepath[0] = '\0';
    filepath = my_strcat(filepath, "./scene/ .txt\0");
    filepath[8] = data->current_scene + 48;
    return (filepath);
}

void new_scene(data_t *data, scene_t *scene)
{
    int fd;
    char *file = malloc(sizeof(char) * 51);
    int y = 0;
    init_scene(scene, data);
    init_data(data);

    fd = open_file(get_scene_filepath(data));
    y = read(fd, file, 50);
    while (y != 0) {
        init_nb(file, data, scene, fd);
        y = read(fd, file, 50);
    }
    init_time_n_clock(data, scene);
    init_button_callback(scene, data);
    free(file);
}

void init_nb(char *file, data_t *data, scene_t *scene, int fd)
{
    if (file[0] == '0' && data->i_buttons < scene->nb_buttons)
        set_button(file, data, scene, data->i_buttons);
    if (file[0] == '1' && data->i_obj < scene->nb_obj)
        set_obj(file, data, scene, data->i_obj);
    if (file[0] == '2')
        set_background(file, data, scene);
    if (file[0] == '3')
        set_sound(scene, file, data->i_sound, data);
    if (file[0] == '5')
        set_player(scene, file);
    if (file[0] == '4')
        set_music(scene, file, data->i_music, data);
}