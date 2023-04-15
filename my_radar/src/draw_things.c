/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** draw
*/

#include "../includes/my.h"

void if_s (MAIN_T *GLOB, PLANE_T *list)
{
    if (GLOB->s == 0) {
        sfRenderWindow_drawSprite(WINDOW, list->sprite, NULL);
    }
}

void my_draw_plane(MAIN_T *GLOB, float seconds)
{
    PLANE_T *list; sfVector2f arrival_pos; sfVector2f actual_pos;
    for (list = RAC->next; list != RAC; list = list->next) {
        arrival_pos.x = list->x_arrival;
        arrival_pos.y = list->y_arrival;
        actual_pos = sfSprite_getPosition(list->sprite);
        list->last_pos.x = actual_pos.x;
        list->last_pos.y = actual_pos.y;
        check_collision(GLOB, list); check_in_tower(GLOB, list);
        if (list->check_pos != 1 && seconds >= list->start_delay &&
        list->collide != 1) {
            if_s(GLOB, list);
            draw_rect(list, GLOB);
        }
    }
}

void draw_rect(PLANE_T *list, MAIN_T *GLOB)
{
    sfVector2f position = sfSprite_getPosition(list->sprite);
    sfRectangleShape_setPosition(list->rect, position);
    if (GLOB->l == 0)
        sfRenderWindow_drawRectangleShape(WINDOW, list->rect, NULL);
}

void draw_circle(TOWER_T *list, MAIN_T *GLOB)
{
    if (GLOB->l == 0)
        sfRenderWindow_drawCircleShape(WINDOW, list->circle, NULL);
}

void my_draw_tower(MAIN_T *GLOB)
{
    TOWER_T *list;
    for (list = RAC_TOW->next; list != RAC_TOW; list = list->next) {
        draw_circle(list, GLOB);
        if (GLOB->s == 0)
            sfRenderWindow_drawSprite(WINDOW, list->sprite, NULL);
        draw_circle(list, GLOB);
    }
}
