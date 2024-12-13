/*
** EPITECH PROJECT, 2019
** fir tree
** File description:
** print tree with the size of the param
** To compile this project : gcc -o main tree.c
*/

#include <stdlib.h>
#include <stdio.h>

static void print_x_characters(int x, char c)
{
    for (int i = 0; i < x; i++)
        putchar(c);
}

static void print_log(int size, int x)
{
    int width_size = size;

    for (int i = 2; i <= size; i += 2)
        if (i == size) {
            width_size++;
            x--;
        }
    for (int y = 1; y <= size; y++) {
        print_x_characters(x, ' ');
        print_x_characters(width_size, '|');
        putchar('\n');
    }
}

static int print_floor(int size, int floor, int top_stars, int num_spaces)
{
    int step;

    for (step = top_stars; step < (floor + 4 + top_stars); step++) {
        print_x_characters(num_spaces, ' ');
        print_x_characters(1 + step * 2, '*');
        num_spaces--;
        putchar('\n');
    }
    return step - 2;
}

static int get_zoom(int size, int spaces)
{
    for (int i = 4; i < size; i += 2)
        spaces += (size - i);
    return spaces;
}

void tree(int size)
{
    int top_stars = 0;
    int num_spaces = get_zoom(size, (size) * 4 - 2);
    int is_decrease = 1;
    int decrease = -1;

    if (size == 1)
        num_spaces++;
    for (int floor = 0; floor < size; floor++) {
        top_stars = print_floor(size, floor, top_stars, num_spaces);
        num_spaces = get_zoom(size, (size * 4 - 1) - top_stars) - 1;
        if (is_decrease)
            decrease++;
        top_stars -= decrease;
        num_spaces += decrease;
        is_decrease = !is_decrease;
    }
    print_log(size, top_stars + 1);
}

int main(const int argc, const char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        return 84;
    }

    tree(atoi(argv[1]));
    return 0;
}