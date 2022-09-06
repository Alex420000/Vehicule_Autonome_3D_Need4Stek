/*
** EPITECH PROJECT, 2021
** need4stek.h
** File description:
** need4stek
*/

#ifndef NEEDFORSTEK_H
#define NEEDFORSTEK_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct car
{
    char array[1];
    char *next;
    char *buffer;
    char **tmp;
    int cols;
    int line_cols;
    int read_line;
    int i;
    int j;
    int x;
    int y;
    int z;
}car;

//end_laps.c
int wall_collision(char **array);
int end_laps(char *next);

//main.c
int needforstek_command(char *exe);
int conduite_autonome(void);
int main(void);

//my_put.c
void my_putchar(char c, int x);
void my_putstr(char *str, int x);
char *manage_float(char *str);
char *line_exit(const int filepath);
char **my_str_to_word_array(char *str, char space);

//wheels.c
int rad_wheels(float nbr, char *data);
int wheels_angle(char **array, float veloce);
int car_velocity(float veloce);

#endif