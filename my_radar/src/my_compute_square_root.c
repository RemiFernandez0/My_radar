/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int stock = 0;
    int square_root = nb / 2;
    while (square_root != stock) {
        stock = square_root;
        square_root = (nb / stock + stock) / 2;
    }
    for (int i = 1; i < nb; i++) {
        if (i * i == nb)
            return (square_root);
    }
    return (0);
}
