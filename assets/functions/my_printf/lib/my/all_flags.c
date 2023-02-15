/*
** EPITECH PROJECT, 2022
** pinches_flags
** File description:
** printf flags
*/


#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../include/my.h"

int print_char(va_list *list)
{
    my_putchar(va_arg(*list, int));
    return (1);
}

void print_str(va_list *list)
{
    my_putstr(va_arg(*list, char*));
}

void print_nbr(va_list *list)
{
    my_put_nbr(va_arg(*list, int));
}

int print_porcentage(va_list *list)
{
    my_putchar('%');
    return (1);
}

void print_oct(va_list *list)
{
    oct(va_arg(*list, unsigned int));
}
