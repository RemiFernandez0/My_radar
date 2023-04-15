/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/

#include "../includes/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int n = 0;
    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
}

void print_timer(MAIN_T *GLOB, float seconds)
{
    char * str;
    str = put_float_to_str(seconds, 3);
    sfText_setString(TEXT[1].text, str);
    sfRenderWindow_drawText(WINDOW, TEXT[0].text, NULL);
    sfRenderWindow_drawText(WINDOW, TEXT[1].text, NULL);
}

void usage_h(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("   path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h                 print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  ‘L’                key enable/disable hitboxes and areas.\n");
    my_putstr("  ‘S’                key enable/disable sprites.\n");
}
