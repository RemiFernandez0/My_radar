/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** check_finish
*/

#include "../includes/my.h"

int check_finish(MAIN_T *GLOB)
{
    PLANE_T *plane;
    int nb_plane = 0;
    int nb_destroy = 0;
    for (plane = RAC->next; plane != RAC; plane = plane->next) {
        if (plane->collide == 1) {
            nb_destroy += 1;
        }
        if (plane->check_pos == 1) {
            nb_destroy += 1;
        }
        nb_plane += 1;
    }
    if (nb_destroy >= nb_plane)
        return 1;
    else
        return 0;
}
