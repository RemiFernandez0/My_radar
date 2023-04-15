/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** add
*/

#include "../includes/my.h"


void add_tower (MAIN_T *GLOB, char ** tab)
{
    TOWER_T *new = malloc(sizeof(*new));
    sfTexture *texture = sfTexture_createFromFile("assets/tower.png", NULL);
    sfVector2f scale = {0.1, 0.1};
    new->pos_x = my_str_to_int(tab[1]);
    new->pos_y = my_str_to_int(tab[2]);
    sfVector2f position = {new->pos_x, new->pos_y};
    new->scope = my_str_to_int(tab[3]);
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, texture, sfTrue);
    sfVector2f center;
    center.x = sfTexture_getSize(texture).x / 2;
    center.y = sfTexture_getSize(texture).y / 2;
    sfSprite_setOrigin(new->sprite, center);
    sfSprite_setPosition(new->sprite, position);
    sfSprite_setScale(new->sprite, scale);
    set_tower_circle(new);
    new->prev = RAC_TOW->prev;
    new->next = RAC_TOW;
    RAC_TOW->prev->next = new;
    RAC_TOW->prev = new;
}

void add_plane (MAIN_T *GLOB, char ** tab)
{
    PLANE_T *new = malloc(sizeof(*new));
    new->sprite = sfSprite_create();
    new->x_start = my_str_to_int(tab[1]);
    new->y_start = my_str_to_int(tab[2]);
    new->x_arrival = my_str_to_int(tab[3]);
    new->y_arrival = my_str_to_int(tab[4]);
    new->speed = my_str_to_int(tab[5]);
    new->start_delay = my_str_to_int(tab[6]);
    new->collide = 0;
    new->check_pos = 0;
    set_plane(new);
    if (new->x_start > new->x_arrival)
        sfSprite_setRotation(new->sprite, 180);
    new->last_pos.x = 0;
    new->last_pos.y = -1;
    new->prev = RAC->prev;
    new->next = RAC;
    RAC->prev->next = new;
    RAC->prev = new;
}
