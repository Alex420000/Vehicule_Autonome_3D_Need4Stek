/*
** EPITECH PROJECT, 2021
** my_put.c
** File description:
** my_put
*/

#include "../include/need4stek.h"

void my_putchar(char c, int x)
{
    write(x, &c, 1);
}

void my_putstr(char *str, int x)
{
    int i = 0;

    while (str[i])
        my_putchar(str[i++], x);
}

char *manage_float(char *str)
{
    struct car value;

    value.i = 0;
    value.j = 0;
    if ((value.buffer = malloc(sizeof(char *) * 100)) == NULL)
        return (NULL);
    while (value.i != 3)
        if (str[value.j++] == ':')
            value.i++;
    value.i = 0;
    while (str[value.j] != 0) {
        if ((str[value.j] >= '0' && str[value.j] <= '9')
            || str[value.j] == '.' || str[value.j] == ':') {
            value.buffer[value.i] = str[value.j];
            value.i++;
        }
        value.j++;
    }
    value.buffer[value.i - 1] = '\0';
    return (value.buffer);
}

char *line_exit(const int filepath)
{
    static car line;

    if ((line.cols == 0 && (line.read_line = read(filepath, line.array, 1)) < 1)
        || (line.line_cols == 0 && (line.next = malloc(5000)) == NULL))
        exit(write(2, "exit\n", 5));
    while (line.cols != line.read_line) {
        if (line.array[line.cols] == '\n' || line.array[line.cols] == 0) {
            line.cols++;
            line.next[line.line_cols] = 0;
            line.line_cols = 0;
            return (line.next);
        }
        line.next[line.line_cols] = line.array[line.cols];
        line.line_cols++;
        line.cols++;
    }
    line.cols = 0;
    line_exit(filepath);
    return (line.next);
}

char **my_str_to_word_array(char *str, char space)
{
    struct car array;

    if ((array.tmp = malloc(sizeof(char **) * strlen(str))) == NULL)
        return (NULL);
    array.x = 0;
    array.y = 0;
    while (str[array.x] != 0) {
        array.z = 0;
        if ((array.tmp[array.y] = malloc(sizeof(char *) * strlen(str))) == NULL)
            return (NULL);
        while (str[array.x] == space && str[array.x++] != 0);
        while (str[array.x] != space && str[array.x] != 0)
        array.tmp[array.y][array.z++] = str[array.x++];
        array.tmp[array.y++][array.z] = 0;
        while (str[array.x] == space && str[array.x++] != 0);
    }
    array.tmp[array.y] = NULL;
    return (array.tmp);
}