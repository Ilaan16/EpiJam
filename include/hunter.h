/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** hunter.h
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "my.h"

//buttons_callback1.c
void exit_game(data_t *data, button_t *button, scene_t **s);
void close_button(data_t *data, scene_t *scene, int i);
void play_button(data_t *data, scene_t *scene, int i);
void pause_button(data_t *data, scene_t *scene, int i);
void menu_button(data_t *data, scene_t *scene, int i);
void pause_button(data_t *data, scene_t *scene, int i);
void menu_button(data_t *data, scene_t *scene, int i);

//buttons_callback2.c
void change_music(data_t *data, scene_t *scene, int i);
void change_sound(data_t *data, scene_t *scene, int i);
void display_sprite(data_t *data, scene_t *scene, int i);
void normal_button(data_t *data, scene_t *scene, int i);
void easy_button(data_t *data, scene_t *scene, int i);
void hard_button(data_t *data, scene_t *scene, int i);

//buttons_callback3.c
void resume_button(data_t *data, scene_t *scene2, int i);
void loop_pause(data_t *data, scene_t *scene, scene_t *scene2);
void leave_how_to(data_t *data, scene_t *scene, int i);
void how_to(data_t *data, scene_t *scene, int i);

//file_parsing.c
int open_file(char *filepath);
int goto_coma(int i, char *file);
char *goto_quote2(int i, char *file, char *filepath);
int goto_quote(int i, char *file);

//free_scene.c
void destroy_buttons(data_t *data, scene_t *scene);
void destroy_obj(data_t *data, scene_t *scene);
void free_current_scene(data_t *data, scene_t *scene);

//get_nb.c
void get_nb_buttons(scene_t *scene, data_t *data);
void get_nb_obj(scene_t *scene, data_t *data);
void get_nb_sound(scene_t *scene, data_t *data);
void get_nb_music(scene_t *scene, data_t *data);
void get_nb_player_text(scene_t *scene, data_t *data);

//game_loop_management.c
void mouse_management(data_t *data, sfEvent *event, button_t *buttons);
void event_management(data_t *data, scene_t *scene);
void player_animation(scene_t *scene, data_t *data);
void game_loop(data_t *data, scene_t *scene);
void check_event(sfEvent event, data_t *data, scene_t *scene);

//init_buttons.c
void init_button(data_t *data, scene_t *scene, int y);
int boutton_is_pressed(scene_t *s, sfVector2f position, data_t *data, int i);
void buttons_clicked(scene_t *scene, data_t *data);
void init_button_callback(scene_t *scene, data_t *data);

//init_rect.c
void init_rect_buttons(data_t *data, scene_t *scene, int y);
void init_rect_obj(data_t *data, scene_t *scene, int y);

//init.c
void init_music(char *filepath, scene_t *scene, int y);
void init_sound(char *filepath, scene_t *scene, int y);
void init_and_draw_background(char *filepath, scene_t *scene, data_t *data);
void init_obj(data_t *data, scene_t *scene);
void buttons_hover(scene_t *scene, data_t *data);
void init_inventory(scene_t *scene, data_t *data);
void init_player(scene_t *scene, char *filepath);
void init_time_n_clock(data_t *data, scene_t *scene);

//play_n_display.c
void draw_sprite(data_t *data, scene_t *scene);
void play_sound(scene_t *scene, int y);
void play_music(scene_t *scene, int y);

//scene.c
char *get_scene_filepath(data_t *data);
void new_scene(data_t *data, scene_t *scene);
void init_nb(char *file, data_t *data, scene_t *scene, int fd);

//set_ressources.c
void set_background(char *file, data_t *data, scene_t *scene);
void set_button(char *file, data_t *data, scene_t *scene, int y);
void set_obj(char *file, data_t *data, scene_t *scene, int y);
void set_player(scene_t *scene, char *file);
void set_sound(scene_t *scene, char *file, int y, data_t *data);
void set_music(scene_t *scene, char *file, int y, data_t *data);

//text.c
void initialise_text(data_t *data);
char *my_int_to_char(int nb);
int number_digits(int nbr);

//window.c
void openwindow(data_t *data);
void initialise_window(data_t *data);

#endif /* !DEFENDER_H_ */
