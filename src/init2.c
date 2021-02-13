/*
** EPITECH PROJECT, 2020
** init2.c
** File description:
** init2
*/

#include "hunter.h"

void init_and_draw_background(char *filepath, scene_t *scene, data_t *data)
{
    scene->background.size_background.x = 1;
    scene->background.size_background.y = 1;
    scene->background.sprite = sfSprite_create();
    scene->background.texture = NULL;
    scene->background.rect = malloc(sizeof(sfIntRect));
    scene->background.rect->left = 1;
    scene->background.rect->top = 1;
    scene->background.rect->height = 1080;
    scene->background.rect->width = 1920;
    scene->background.texture = \
    sfTexture_createFromFile(filepath, scene->background.rect);
    sfSprite_setTexture(scene->background.sprite, scene->background.texture, \
    sfTrue);
    sfSprite_scale(scene->background.sprite, \
    scene->background.size_background);
    sfRenderWindow_drawSprite(data->window, scene->background.sprite, NULL);
}

void init_player(scene_t *scene, char *filepath)
{
    scene->player.rect = malloc(sizeof(sfIntRect) * 1);

    if (scene->player.i_texture[scene->player.status] <= \
    scene->player.nb_player_text)
        scene->player.texture[scene->player.status][scene->player.i_texture\
        [scene->player.status]] = sfTexture_createFromFile(filepath, NULL);
    if (scene->player.i_texture[0] == 0) {
        scene->player.sprite = sfSprite_create();
        sfSprite_setPosition(scene->player.sprite, scene->player.pos);
        sfSprite_setTexture(scene->player.sprite, scene->player.texture\
        [scene->player.status][scene->player.i_texture[scene->player.status]]\
        ,sfTrue);
    }
    scene->player.i_texture[scene->player.status]++;
}

void set_player(scene_t *scene, char *file)
{
    char *filepath = malloc(sizeof(char) * 51);
    int i = 0;
    scene->player.dead = 0;

    if (scene->player.i_texture[scene->player.status] == 9)
        scene->player.status++;

    filepath = goto_quote2(0, file, filepath);
    if (scene->player.i_texture[0] == 0) {
        i = goto_quote(i, file);
        scene->player.pos.x = my_getnbr(file + i);
        i = goto_coma(i, file);
        scene->player.pos.y = my_getnbr(file + i);
        i = goto_coma(i, file);
        scene->player.size.x = my_getnbr(file + i);
        i = goto_coma(i, file);
        scene->player.size.y = my_getnbr(file + i);
    }
    init_player(scene, filepath);
    free(filepath);
}