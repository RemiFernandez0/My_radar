/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/

#ifndef MY_STRUCT_H
    #define MY_STRUCT_H

typedef struct WINDOW {
    sfRenderWindow *window;
    sfEvent event;
    int nb_plane;
} WIN_T;

typedef struct BACKGROUND {
    sfTexture *texture;
    sfSprite  *sprite;
    sfVector2f scale;
    sfVector2f origin;
    sfVector2f position;
    sfFloatRect rect;
    sfIntRect rect_sprite;
} BACKGROUND_T;

typedef struct CIRCLE {
    sfCircleShape *circle;
} CIRCLE_T;

typedef struct TOWER {
    sfSprite *sprite;
    int pos_x;
    int pos_y;
    int scope;
    sfCircleShape *circle;
    struct TOWER *next;
    struct TOWER *prev;
} TOWER_T;

typedef struct PLANE {
    sfSprite *sprite;
    int x_start;
    int y_start;
    int x_arrival;
    int y_arrival;
    int speed;
    int start_delay;
    int check_pos;
    sfVector2f last_pos;
    sfVector2f center;
    sfRectangleShape* rect;
    int collide;
    struct PLANE *next;
    struct PLANE *prev;
} PLANE_T;

typedef struct STR {
    sfText *text;
    sfVector2f pos;
    sfFont *font;
} TEXT_T;

typedef struct MAIN_STRUCT {
    WIN_T param;
    BACKGROUND_T background;
    PLANE_T *racine_plane;
    TOWER_T *racine_tower;
    int l;
    int s;
    TEXT_T *text;
} MAIN_T;

#endif
