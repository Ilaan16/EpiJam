/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int	neg;
    int	result;
    int	index;

    index = result = 0;
    neg = 1;
    while (str[index] == '-' || str[index] == '+') {
        if (str[index] == '-') {
            neg = neg * -1;
        }
        index++;
    }
    while (str[index] != '\0') {
        if (str[index] < '0' || str[index] > '9') {
            return (result * neg);
        }
        result = (result * 10) + str[index] - 48;
        index++;
    }
    return (result * neg);
}