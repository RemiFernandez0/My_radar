/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** set
*/
#include "../includes/my.h"

void set_plane(PLANE_T *new)
{
    new->rect = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile("assets/plane.png", NULL);
    sfVector2f scale = {1, 1};
    sfVector2f position = {new->x_start, new->y_start};
    sfSprite_setTexture(new->sprite, texture,  sfTrue);
    new->center.x = sfTexture_getSize(texture).x / 2;
    new->center.y = sfTexture_getSize(texture).y / 2;
    sfSprite_setOrigin(new->sprite, new->center);
    sfSprite_setScale(new->sprite, scale);
    sfSprite_setPosition(new->sprite, position);
    sfRectangleShape_setOrigin(new->rect, new->center);
    sfVector2f size = { 20.0f, 20.0f };
    sfRectangleShape_setSize(new->rect, size);
    sfRectangleShape_setOutlineColor(new->rect, sfBlue);
    sfRectangleShape_setOutlineThickness(new->rect, 5.0f);
    sfRectangleShape_setFillColor(new->rect, sfTransparent);
}

void set_tower_circle(TOWER_T *new)
{
    new->circle = sfCircleShape_create();
    sfCircleShape_setRadius(new->circle, (1920 * new->scope) / 100);
    sfVector2f center;
    center.x = (1920 * new->scope) / 100;
    center.y = (1920 * new->scope) / 100;
    sfCircleShape_setOrigin(new->circle, center);
    sfCircleShape_setPosition(new->circle, (sfVector2f){new->pos_x,
                                                        new->pos_y});
    sfCircleShape_setOutlineColor(new->circle, sfBlue);
    sfCircleShape_setOutlineThickness(new->circle, 5.0f);
    sfCircleShape_setFillColor(new->circle, sfTransparent);
}
