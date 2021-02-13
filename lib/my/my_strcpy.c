/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** i dont know
*/

char *my_strcpy(char *dest, char const *src)
{
    int x = 0;

    while (src[x] != '\0')
    {
        dest[x] = src[x];
        x++;
    } dest[x] = src[x];
    return (dest);
}