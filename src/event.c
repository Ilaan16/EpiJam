/*
** EPITECH PROJECT, 2020
** event_manegement
** File description:
** event
*/

#include "hunter.h"

void mouse_management(data_t *data, sfEvent *event, button_t *buttons)
{
    sfVector2i pos = {0, 0};

    if (event->mouseButton.button == sfMouseLeft)
        data->mouse.click = 1;

    pos = sfMouse_getPositionRenderWindow(data->window);
    data->mouse.x = pos.x;
    data->mouse.y = pos.y;
}

void event_management(data_t *data, scene_t *scene)
{
    sfEvent event;
    mouse_management(data, &event, scene->buttons);
    buttons_hover(scene, data);
    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
        }
        if (event.type == sfEvtMouseMoved && data->current_scene >= 2 \
        && data->current_scene != 8)
        if (event.type == sfEvtMouseButtonPressed) {
            data->mouse.click = 0;
            mouse_management(data, &event, scene->buttons);
            if (data->mouse.click == 1) {
                buttons_clicked(scene, data);
            }
        }
        check_event(event, data, scene);
    }
}