/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/

#include "../includes/my.h"
#include "math.h"

sfVector2f scalar_product(sfVector2f move_vect, float elapsedSeconds)
{
    sfVector2f v;
    v.x = move_vect.x * elapsedSeconds;
    v.y = move_vect.y * elapsedSeconds;
    return v;
}

void move_plane2(sfVector2f move_vector, float elapsedSeconds, PLANE_T *list,
float seconds)
{
    if (seconds >= list->start_delay) {
        sfSprite_move(list->sprite, scalar_product(move_vector,elapsedSeconds
        * list->speed));
    }
}

void move_plane(MAIN_T *GLOB, sfClock* clock, float seconds)
{
    PLANE_T *list; sfVector2f position_arrival; sfVector2f position_plane;
    sfTime elapsed = sfClock_getElapsedTime(clock);
    float elaspedSeconds = sfTime_asSeconds(elapsed); float dist;
    for (list = RAC->next; list != RAC; list = list->next) {
        position_arrival.x = list->x_arrival; position_arrival.y =
        list->y_arrival;
        position_plane = sfSprite_getPosition(list->sprite);
        sfVector2f move_vector = {list->x_arrival - position_plane.x,
        list->y_arrival - position_plane.y};
        dist = sqrt(pow(move_vector.x, 2) + pow(move_vector.y, 2));
        if (dist > 0) {
            move_vector.x /= dist; move_vector.y /= dist;
        }
        move_plane2(move_vector, elaspedSeconds, list, seconds);
        position_plane = sfSprite_getPosition(list->sprite);
        if (fabs(position_plane.x - list->x_arrival) < 1.5 && fabs
        (position_plane.y - list->y_arrival) <
        1)
            list->check_pos = 1;
    } sfClock_restart(clock);
}
