/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/
#include "../includes/my.h"
#include "math.h"

int check_collision(MAIN_T *GLOB, PLANE_T *plane)
{
    sfVector2f position;
    sfVector2f position2;
    for (PLANE_T *list = plane->next; list != plane; list = list->next) {
        if (list == RAC)
            list = list->next;
        if (list == plane)
            return 0;
        position = sfSprite_getPosition(plane->sprite);
        position2 = sfSprite_getPosition(list->sprite);
        if ((position.x < position2.x + 20) &&
            (position.x + 20 > position2.x) &&
            (position.y < position2.y + 20) &&
            (position.y + 20 > position2.y)) {
            list->collide = 1;
            plane->collide = 1;
        }
    }
    return 0;
}

void check_in_tower(MAIN_T *GLOB, PLANE_T *plane)
{
    float circle_radius;
    float square_half_size;
    TOWER_T *tower = RAC_TOW->next;
    sfVector2f square_pos = sfRectangleShape_getPosition(plane->rect);
    square_half_size = sfRectangleShape_getSize(plane->rect).x / 2;
    for (TOWER_T *tower = RAC_TOW->next; tower != RAC_TOW; tower =
        tower->next) {
        sfVector2f circle_pos = sfCircleShape_getPosition(tower->circle);
        circle_radius = sfCircleShape_getRadius(tower->circle);
        if (sqrt(pow(circle_pos.x - square_pos.x, 2) +
            pow(circle_pos.y - square_pos.y, 2)) <
            square_half_size + circle_radius) {
            plane->collide = 0;
        }
    }
}
