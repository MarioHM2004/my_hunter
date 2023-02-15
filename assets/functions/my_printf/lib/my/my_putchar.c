/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print messages on a screen
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
