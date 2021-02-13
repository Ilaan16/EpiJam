/*
** EPITECH PROJECT, 2020
** MUL_my_hunter_2020
** File description:
** text.c
*/

#include "hunter.h"

void initialise_text(data_t *data)
{
    data->text.font = sfFont_createFromFile("scene/Horizon.otf");
    data->text.text = sfText_create();
    sfText_setColor(data->text.text, sfWhite);
    sfText_setStyle(data->text.text, sfTextBold);
    sfText_setString(data->text.text, " HUNTER\0");
    sfText_setFont(data->text.text, data->text.font);
    sfText_setCharacterSize(data->text.text, 210);
    sfText_setPosition(data->text.text, (sfVector2f){450, 230});
}