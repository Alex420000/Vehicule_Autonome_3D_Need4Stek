/*
** EPITECH PROJECT, 2021
** end_laps.c
** File description:
** end_laps
*/

#include "../include/need4stek.h"

int wall_collision(char **array)
{
    int x = 2;

    while (x != 30) {
        if (atof(array[x++]) <= 10) {
            return (1);
        }
    }
    return (0);
}

int end_laps(char *next)
{
    int x = strlen(next) - 1;
    int y = 0;
    char *array;

    if ((array = malloc(sizeof(char *) * strlen(next))) == NULL)
        return (-1);
    for (; next[x] != ':' && next[x] != 0; x--);
    x--;
    for (; next[x] != ':' && next[x] != 0; x--);
    x++;
    while (next[x] != ':' && next[x] != 0)
        array[y++] = next[x++];
    array[y] = 0;
    if (strcmp("Track Cleared", array) == 0) {
        free(array);
        needforstek_command("STOP_SIMULATION\n");
        return (1);
    }
    free(array);
    return (0);
}