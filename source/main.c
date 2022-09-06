/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../include/need4stek.h"

int needforstek_command(char *exe)
{
    my_putstr(exe, 1);
    exe = line_exit(0);
    if (end_laps(exe) == 1)
        return (1);
    return (0);
}

int conduite_autonome(void)
{
    float veloce;
    char *line;
    char **array;

    while (1) {
        my_putstr("GET_INFO_LIDAR\n", 1);
        line = line_exit(0);
        end_laps(line);
        line = manage_float(line);
        array = my_str_to_word_array(line, ':');
        veloce = atof(array[15]);
        if (car_velocity(veloce) == 1)
            break;
        my_putstr("GET_INFO_LIDAR\n", 1);
        line = line_exit(0);
        end_laps(line);
        line = manage_float(line);
        array = my_str_to_word_array(line, ':');
        veloce = atof(array[15]);
        if (wheels_angle(array, veloce) == 1)
            break;
    }
    return (0);
}

int main(void)
{
    needforstek_command("START_SIMULATION\n");
    conduite_autonome();
    return (0);
}