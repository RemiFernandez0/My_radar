/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-remi.fernandez
** File description:
** strlen modified
*/

int my_strlen(char *str, int i)
{
    while (str[i] != ' ') {
        if (str[i] == '\n')
            break;
        if (str[i] == '\0')
            break;
        i++;
    }
    return i;
}
