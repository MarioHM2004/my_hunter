/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

void my_putchar (char c);
int my_nbrlen(long int num);

int my_put_nbr (int nb)
{

    if (nb < 0 && nb > -2147483648){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10){
        my_put_nbr(nb / 10);

    }
    my_putchar('0' + (nb % 10));
    return (my_nbrlen(nb));
}
