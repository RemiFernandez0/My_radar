/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/

#include "../includes/my.h"

int my_char_is_num(char c)
{
    if (c >= 48 && c <= 57) {
        return 1;
    }
    return 0;
}

int check_script(char * script)
{
    int i = 0;
    while (script[i] != '\0') {
        if (script[0] != 'A' && script[0] != 'T') {
            return 84;
        }
        if (script[i] == '\n' && script[i + 1] != 'A' && script[i + 1] != 'T'
        && script[i + 1] != '\0' && script[i + 1] != '\n') {
            return 84;
        }
        if (script[i] != '\n' && script[i] != ' ' && script[i] != '\0' &&
            my_char_is_num(script[i]) == 0 && script[i] != 'A' && script[i]
            != 'T' && script[i] != '\0') {
            return 84;
        }
        i++;
    }
    return 0;
}

int check_assets(MAIN_T *GLOB)
{
    sfTexture *texture;
    sfTexture *texture2;
    if (!(texture = sfTcf("assets/plane.png", NULL)))
        return 84;
    if (!(texture2 = sfTcf("assets/tower.png", NULL)))
        return 84;
    sfTexture_destroy(texture);
    sfTexture_destroy(texture2);
    return 0;
}
