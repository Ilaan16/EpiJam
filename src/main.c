/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** main.c
*/

#include "hunter.h"

int check_arg(int ac, char **av)
{
    if (ac == 1)
        return (0);
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("You need start program with ./my_hunter\n");
            return (84);
        } else {
            my_putstr("Try with -h\n");
            return (84);
        }
    } else {
        my_putstr("Try with -h\n");
        return (84);
    }
}

int main(int argc, char **argv)
{
    scene_t scene;
    data_t data;
    button_t buttons;
    data.current_scene = 0;

    if (check_arg(argc, argv) == 84)
        return (84);
    initialise_text(&data);
    initialise_window(&data);
    new_scene(&data, &scene);
    while (sfRenderWindow_isOpen(data.window)) {
        game_loop(&data, &scene);
    }
    sfRenderWindow_destroy(data.window);
    free_current_scene(&data, &scene);
}
