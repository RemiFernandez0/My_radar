/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/

#include <stdlib.h>

int my_countlen_int(int nb)
{
    int count = 0;
    while (nb >= 10) {
        count++;
        nb = nb / 10;
    }
    return count;
}

int my_int_to_str(int nb, char *str)
{
    int count = my_countlen_int(nb);
    int count_base = count;
    while (nb >= 10) {
        str[count] = 48 + nb % 10;
        count--;
        nb = nb / 10;
    }
    str[0] = 48 + nb % 10;
    str[count_base + 1] = '\0';
    return count_base + 1;
}

void my_float_to_str(float nb, char* str, int afterpoint)
{
    int i = 0; int integer = (int) nb;
    float floatpart = (float) nb - (float) integer;
    int floatpart_int = 0;
    int power = 10; int count; int count_base;
    for (i = 0; i != afterpoint - 1; i++)
        power *= 10;
    floatpart *= power;
    i = my_int_to_str(integer, str);
    str[i] = '.';
    i += 1;
    floatpart_int = (int) floatpart;
    count = my_countlen_int(floatpart_int);
    count_base = count;
    while (floatpart_int >= 10) {
        str[i + count] = 48 + floatpart_int % 10;
        floatpart_int = floatpart_int / 10;
        count--;
    }
    str[i] = floatpart_int % 10 + 48;
    str[i + count_base + 1] = '\0';
}

char * put_float_to_str(float nb, int afterpoint)
{
    int count = my_countlen_int(nb);
    char *str = malloc(sizeof(char) * (count + afterpoint + 1));
    my_float_to_str(nb, str, afterpoint);
    return str;
}
