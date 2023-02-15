/*
** EPITECH PROJECT, 2022
** utils_functions
** File description:
** functions for printf
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/print.h"

int oct(unsigned int n)
{
    unsigned int o = 0;
    int value = 1;
    int rest = 0;

    while (n != 0){
        rest = n % 8;
        o += rest * value;
        value = value * 10;
        n = n / 8;
    }
    my_put_nbr(o);
    return (my_nbrlen(o));
}

char *hexa_mayus(unsigned int n)
{
    char *hex = malloc(sizeof(char) * (my_nbrlen(n) + 1));
    for (int i = 0; i <= my_nbrlen(n); i++)
        hex[i] = '\0';
    int i = 0;
    int r = 0;

    while (n != 0){
        r = n % 16;
        if (r < 10) {
            hex[i] = r + 48;
            i = i + 1;
        }else{
            hex[i] = r + 55;
            i = i + 1;
        }
        n = n / 16;
    }
    my_revstr(hex);
    return (hex);
}

char *hexa_minus(unsigned int n)
{
    char *hex = malloc(sizeof(char) * (my_nbrlen(n) + 1));
    for (int i = 0; i <= my_nbrlen(n); i++)
        hex[i] = '\0';
    int i = 0;
    int r = 0;

    while (n != 0){
        r = n % 16;
        if (r < 10) {
            hex[i] = r + 48;
            i = i + 1;
        }else{
            hex[i] = r + 87;
            i = i + 1;
        }
        n = n / 16;
    }
    my_revstr(hex);
    return (hex);
}

int my_put_unsigned_nbr (unsigned int nb)
{
    if (nb >= 10)
        my_put_unsigned_nbr(nb / 10);
    my_putchar('0' + (nb % 10));
    return (my_nbrlen(nb));
}
