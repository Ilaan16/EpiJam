/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** display a letter on terminal
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}