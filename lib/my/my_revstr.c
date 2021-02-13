/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** i dont know
*/

#include "my.h"

char *my_revstr(char *str)
{
    int	begin;
    int	end;
    char	tmp;

    begin = 0;
    end = my_strlen(str) - 1;
    while (begin < end) {
        tmp = str[begin];
        str[begin] = str[end];
        str[end] = tmp;
        begin++;
        end--;
    }
    return (str);
}