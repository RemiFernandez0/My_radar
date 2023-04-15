/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/

#ifndef MY_H
    #define MY_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "../includes/my_struct.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "errno.h"

    #define WINDOW GLOB->param.window
    #define EVENT GLOB->param.event
    #define MAP GLOB->background
    #define sfTcf sfTexture_createFromFile
    #define RAC GLOB->racine_plane
    #define RAC_TOW GLOB->racine_tower
    #define TEXT GLOB->text

int my_strlen(char const *str, int i);
int my_fill_tab(MAIN_T *GLOB, char *script, int i);
int put_in_chained(MAIN_T *GLOB, char *script);
int my_str_to_int(char * str);
void intialise_list(MAIN_T *GLOB);
void move_plane(MAIN_T *GLOB, sfClock* clock, float seconds);
void my_draw_tower(MAIN_T *GLOB);
void make_double_tab(MAIN_T *GLOB, char *script);
void set_plane(PLANE_T *new);
void set_tower_circle(TOWER_T *new);
int init_background(MAIN_T *GLOB);
void intialise_list(MAIN_T *GLOB);
void my_draw_plane(MAIN_T *GLOB, float seconds);
void draw_circle(TOWER_T *list, MAIN_T *GLOB);
void my_draw_tower(MAIN_T *GLOB);
void add_plane (MAIN_T *GLOB, char ** tab);
void add_tower (MAIN_T *GLOB, char ** tab);
int check_collision(MAIN_T *GLOB, PLANE_T *plane);
void check_l(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed);
void check_l2(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
void check_in_tower(MAIN_T *GLOB, PLANE_T *plane);
int check_finish(MAIN_T *GLOB);
int check_script(char * script);
int check_assets(MAIN_T *GLOB);
int my_fill_tab_plane(MAIN_T *GLOB, char *script, int i);
int my_fill_tab_tower(MAIN_T *GLOB, char *script, int i);
void draw_rect(PLANE_T *list, MAIN_T *GLOB);
void check_s(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed);
void check_s2(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed);
char * put_float_to_str(float nb, int afterpoint);
int init_text(MAIN_T *GLOB);
void print_timer(MAIN_T *GLOB, float seconds);
void usage_h(void);
#endif
