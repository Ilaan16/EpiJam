/*
** EPITECH PROJECT, 2020
** task01my_swap
** File description:
** i dont know
*/

int my_swap(int *pointeur_a, int *pointeur_b)
{
    int mem;

    mem = *pointeur_a;
    *pointeur_a = *pointeur_b;
    *pointeur_b = mem;
    return (0);
}
