/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** TODO: add description
*/
#include "../includes/my.h"

int put_in_chained(MAIN_T *GLOB, char *script)
{
    int i = 0;
    intialise_list(GLOB);
    if (script[0] == 'A')
        my_fill_tab_plane(GLOB, script, i);
    if (script[0] == 'T')
        my_fill_tab_tower(GLOB, script, i);
    while (script[i] != '\0') {
        if (script[i] == '\n' && script[i + 1] == 'A') {
            my_fill_tab_plane(GLOB, script, i + 1);
        }
        if (script[i] == '\n' && script[i + 1] == 'T') {
            my_fill_tab_tower(GLOB, script, i + 1);
        }
            i++;
    }
    return 0;
}

void my_fill_tab_tower2(MAIN_T *GLOB, char *script, int i, char **tab)
{
    int n_param = 3;
    int j = 0;
    tab[n_param] = malloc(sizeof(**tab) * my_strlen(script, i));
    while (script[i] >= 48 && script[i] <= 57) {
        tab[n_param][j] = script[i];
        i++;
        j++;
    }
    tab[n_param][j] = '\0';
    tab[n_param + 1] = 0;
    if (tab[0][0] == 'T')
        add_tower(GLOB, tab);
}

int my_fill_tab_tower(MAIN_T *GLOB, char *script, int i)
{
    char **tab; int n_param = 1; int j = 0;
    if (!(tab = malloc(sizeof(*tab) * 7)))
        return 84;
    tab[0] = malloc(sizeof(char) * 2);
    tab[0] = "T";
    do { if (script[i] == '\0')
            break;
        if (script[i] >= 48 && script[i] <= 57) {
            tab[n_param] = malloc(sizeof(**tab) * ((my_strlen(script, i) + 2)));
            while (script[i] >= 48 && script[i] <= 57) {
                tab[n_param][j] = script[i];
                j++;
                i++;
            } tab[n_param][j] = '\0';
            n_param += 1; j = 0;
        } i++;
        if (n_param >= 3)
            break; } while (script[i] != '\n');
    my_fill_tab_tower2(GLOB, script, i, tab);
    return 0;
}

void my_fill_tab_plane2(MAIN_T *GLOB, char *script, int i, char **tab)
{
    int n_param = 6;
    int j = 0;
    tab[n_param] = malloc(sizeof(**tab) * my_strlen(script, i));
    while (script[i] >= 48 && script[i] <= 57) {
        tab[n_param][j] = script[i];
        i++;
        j++;
    }
    tab[n_param][j] = '\0';
    tab[n_param + 1] = 0;
    if (tab[0][0] == 'A')
        add_plane(GLOB, tab);
}

int my_fill_tab_plane(MAIN_T *GLOB, char *script, int i)
{
    char **tab; int n_param = 1; int j = 0;
    if (!(tab = malloc(sizeof(*tab) * 10)))
        return 84;
    tab[0] = malloc(sizeof(char) * 2);
    tab[0] = "A";
    do {
        if (script[i] == '\0')
            break;
        if (script[i] >= 48 && script[i] <= 57) {
            tab[n_param] = malloc(sizeof(**tab) * ((my_strlen(script, i) + 2)));
            while (script[i] >= 48 && script[i] <= 57) {
                tab[n_param][j] = script[i];
                j++; i++;
            } tab[n_param][j] = '\0';
            n_param += 1; j = 0;
        } i++;
        if (n_param >= 6)
            break;
    } while (script[i] != '\n');
    my_fill_tab_plane2(GLOB, script, i ,tab); return 0;
}
