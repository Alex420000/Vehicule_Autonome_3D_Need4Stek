/*
** EPITECH PROJECT, 2021
** wheels.c
** File description:
** wheels
*/

#include "../include/need4stek.h"

int rad_wheels(float nbr, char *data)
{
    my_putstr("WHEELS_DIR:", 1);
    if (nbr < 0.0) 
        my_putchar('-', 1);
    my_putstr(data, 1);
    data = line_exit(0);
    if (end_laps(data) == 1)
        return (1);
    return (0);
}

int car_velocity(float veloce)
{
    if (veloce >= 10000)
        return (needforstek_command("car_forward:1.0\n"));
    if (veloce >= 5000)
        return (needforstek_command("car_forward:0.9\n"));
    if (veloce >= 1000)
        return (needforstek_command("car_forward:0.7\n"));
    if (veloce >= 600)
        return (needforstek_command("car_forward:0.5\n"));
    if (veloce >= 400)
        return (needforstek_command("car_forward:0.3\n"));
    return (needforstek_command("car_forward:0.1\n"));
}

int wheels_angle(char **array, float veloce)
{
    float angle_pos;
    float angle_neg;

    angle_pos = atof(array[1]);
    angle_neg = atof(array[31]);
    if (veloce >= 5000)
        return (rad_wheels(angle_pos - angle_neg, "0.005\n"));
    if (veloce >= 1000)
        return (rad_wheels(angle_pos - angle_neg, "0.05\n"));
    if (veloce >= 600)
        return (rad_wheels(angle_pos - angle_neg, "0.1\n"));
    if (veloce >= 400)
        return (rad_wheels(angle_pos - angle_neg, "0.2\n"));
    if (veloce >= 200)
        return (rad_wheels(angle_pos - angle_neg, "0.3\n"));
    return (rad_wheels(angle_pos - angle_neg, "0.5\n"));
}