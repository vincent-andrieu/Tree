/*
** EPITECH PROJECT, 2019
** fir tree
** File description:
** print tree with the size of the param
*/

void my_putchar(char c);

static void print_x_characters(int x, char c)
{
    for (int i = 0; i < x; i++) {
        my_putchar(c);
    }
}

static void print_trunk(int size, int zoom)
{
    for (int y = 1; y <= size; y++) {
        print_x_characters((size - 2) * 4 + 12 - size / 2, ' ');
        print_x_characters(size, '|');
        my_putchar('\n');
    }
}

static int print_floor(int size, int floor, int top_stars, int num_spaces)
{
    int step;

    for (step = top_stars; step < (floor + 4 + top_stars); step++) {
        print_x_characters(num_spaces, ' ');
        print_x_characters(1 + step * 2, '*');
        num_spaces--;
        my_putchar('\n');
    }
    return (step - 2);
}

void tree(int size)
{
    int top_stars = 0;
    int num_spaces = (size - 2) * 4 + 12;

    for (int floor = 0; floor < size; floor++) {
        top_stars = print_floor(size, floor, top_stars, num_spaces);
        num_spaces  = ((size - 2) * 4 + 12) - (top_stars);
    }
    print_trunk(size, (size - 2) * 4 + 12);
}

//Etage du dessus = 2/3 * Etage
//Etage du dessous = 2/3 / Etage
//Espaces en haut avant première étoile = 5*4 - 1
//Dernière ligne avant tronc = size*4
//v_ligne = (size - 2) * 8 + 13
