/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** init
*/

#include "../includes/my.h"

int init_background(MAIN_T *GLOB)
{
    if (!(MAP.texture = sfTcf("assets/map.jpg", NULL)))
        return 84;
    MAP.sprite = sfSprite_create();
    MAP.scale.x = 1;
    MAP.scale.y = 0.91;
    sfSprite_setTexture(MAP.sprite,MAP.texture,
                        sfTrue);
    sfSprite_setScale(MAP.sprite, MAP.scale);
    return 0;
}

void intialise_list(MAIN_T *GLOB)
{
    RAC = malloc(sizeof(*RAC));
    RAC->x_start = 0;
    RAC->y_start = 0;
    RAC->x_arrival = 0;
    RAC->y_arrival = 0;
    RAC->speed = 0;
    RAC->start_delay = 0;
    RAC->next = RAC;
    RAC->prev = RAC;

    RAC_TOW = malloc(sizeof(*RAC_TOW));
    RAC_TOW->pos_y = 0;
    RAC_TOW->pos_x = 0;
    RAC_TOW->scope = 0;
    RAC_TOW->next = RAC_TOW;
    RAC_TOW->prev = RAC_TOW;
}

int init_text(MAIN_T *GLOB)
{
    TEXT = malloc(sizeof(TEXT_T) * 2);
    TEXT[0].text = sfText_create();
    if (!(TEXT[0].font = sfFont_createFromFile("assets/RockFont.ttf")))
        return 84;
    TEXT[0].pos.x = 1500;
    TEXT[0].pos.y = 0;
    sfText_setFont(TEXT[0].text,TEXT[0].font);
    sfText_setString(TEXT[0].text, "Timer : ");
    sfText_setPosition(TEXT[0].text, TEXT[0].pos);
    sfText_setColor(TEXT[0].text, sfWhite);

    TEXT[1].text = sfText_create();
    TEXT[1].pos.x = 1675;
    TEXT[1].pos.y = 0;
    sfText_setFont(TEXT[1].text,TEXT[0].font);
    sfText_setPosition(TEXT[1].text, TEXT[1].pos);
    sfText_setColor(TEXT[1].text, sfWhite);
    return 0;
}
