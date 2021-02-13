/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display string on terminal
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, str, my_strlen(str));
    } return (0);
}