/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    char exept = 0x30;

    if (nb == -2147483648) {
        exept = 0x31;
        nb++;
    }
    if (nb < 0) {
        nb = (-1) * nb;
        my_putchar(0x2d);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(exept + nb % 10);
    } else {
        my_putchar(exept + nb);
    }
    return (0);
}