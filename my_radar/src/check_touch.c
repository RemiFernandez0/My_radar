/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/
#include "../includes/my.h"

void check_l(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed)
{
    if (sfTime_asMilliseconds(elapsed) > 200) {
        sfClock_restart(clock3);
        GLOB->l = 0;
    }
}

void check_l2(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed)
{
    if (sfTime_asMilliseconds(elapsed) > 200) {
        sfClock_restart(clock3);
        GLOB->l = 1;
    }
}

void check_s(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed)
{
    if (sfTime_asMilliseconds(elapsed) > 200) {
        sfClock_restart(clock3);
        GLOB->s = 0;
    }
}

void check_s2(MAIN_T *GLOB, sfClock *clock3, sfTime elapsed)
{
    if (sfTime_asMilliseconds(elapsed) > 200) {
        sfClock_restart(clock3);
        GLOB->s = 1;
    }
}
