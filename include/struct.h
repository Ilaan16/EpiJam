/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "hunter.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

typedef struct mouse mouse_t;
typedef struct text text_t;
typedef struct data data_t;
typedef struct save_info save_info_t;
typedef struct button button_t;
typedef struct obj obj_t;
typedef struct sound sound_t;
typedef struct player player_t;
typedef struct music music_t;
typedef struct background background_t;
typedef struct scene scene_t;

struct mouse
{
    int click;
    int x;
    int y;
};

struct text
{
    sfText *text;
    sfFont *font;
};

struct data
{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfClock *clock;
    sfTime *time;
    mouse_t mouse;
    text_t text;
    int width;
    int height;
    int bitsPerPixel;
    int current_scene;
    int speed;
    int i_buttons;
    int score;
    int life;
    int i_obj;
    int i_music;
    int i_sound;
    int i_inventory;
};

struct player
{
    sfTexture ***texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect *rect;
    sfVector2f move;
    sfClock *move_player_clock;
    sfTime *move_player_time;
    int status;
    int dead;
    int i_texture[4];
    int nb_player_text;
};

struct button
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    sfVector2f pos;
    sfVector2f size;
    int status;
    void (*callback)(data_t *data, scene_t *s, int i);
};

struct obj
{
    sfIntRect *rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    int type;
    int status;
    void (*callback)(data_t *data, scene_t *s, int i);
};

struct sound
{
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
};

struct music
{
    sfMusic *music;
    float volume;
};

struct background
{
    sfVector2f size_background;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect *rect;
};

struct scene
{
    background_t background;
    sound_t *sound;
    music_t *music;
    button_t *buttons;
    obj_t *obj;
    player_t player;
    int nb_sound;
    int nb_music;
    int nb_buttons;
    int nb_obj;
};

#endif /* !STRUCT_H_ */
