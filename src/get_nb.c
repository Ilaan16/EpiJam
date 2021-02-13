/*
** EPITECH PROJECT, 2020
** get_nb.c
** File description:
** get_nb
*/

#include "hunter.h"

void get_nb_buttons(scene_t *scene, data_t *data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->nb_buttons = 0;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '0')
            scene->nb_buttons++;
        y = read(fd, type, 50);
    }
    close(fd);
}

void get_nb_obj(scene_t *scene, data_t *data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->nb_obj = 0;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '1')
            scene->nb_obj++;
        y = read(fd, type, 50);
    }
    close(fd);
}

void get_nb_sound(scene_t *scene, data_t *data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->nb_sound = 0;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '3')
            scene->nb_sound++;
        y = read(fd, type, 50);
    }
    close(fd);
}

void get_nb_music(scene_t *scene, data_t *data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->nb_music = 0;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '4')
            scene->nb_music++;
        y = read(fd, type, 50);
    }
    close(fd);
}

void get_nb_player_text(scene_t *scene, data_t *data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->player.nb_player_text = 0;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '5')
            scene->player.nb_player_text++;
        y = read(fd, type, 50);
    }
    close(fd);
}