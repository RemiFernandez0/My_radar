/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-pushswap-remi.fernandez
** File description:
** TODO: add description
*/

#include "../includes/my.h"

int my_str_to_int(char * str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\0') {
        if (str[i] != '-') {
            nb = nb * 10 + (str[i] - 48);
        }
        i++;
    }
    if (str[0] == '-')
        nb = -nb;
    return nb;
}
