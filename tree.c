/*
** EPITECH PROJECT, 2019
** fir tree
** File description:
** print tree with the size of the param
*/

void my_putchar(char c);

void print_trunk(int size)
{
    for (int y = 1; y <= size; y++) {
        print_x_characters(/*XXXXXXXXXX*/, ' ');
        print_x_characters(size, '|');
    }
}

static print_x_characters(int x, char c)
{
    for (int i = 0; i < x; i++) {
        my_putchar(c);
    }
}

static int print_floor(int size, int floor)
{
    int step;
    int num_spaces = size * 4;

    for (step = 0; step <= (floor + 4); step++) {
        //my_put_nbr(num_spaces);
        print_x_characters(num_spaces, ' ');
        print_x_characters(1 + step * 2, '*');
        num_spaces--;
        my_putchar('\n');
    }
    return (1 + step * 2);
}

void tree(int size)
{
    print_x_characters(3, '\n');
    for (int floor = 0; floor < size; floor++) {
        print_floor(size, floor);
    }
    print_trunk();
}


//Etage du dessus = 2/3 * Etage
//Etage du dessous = 2/3 / Etage
//Espaces en haut avant première étoile = 5*4 - 1
//Dernière ligne avant tronc = size*4
