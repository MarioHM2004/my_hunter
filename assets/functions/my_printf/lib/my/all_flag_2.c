/*
** EPITECH PROJECT, 2022
** pinches_flags
** File description:
** printf flags
*/

#include <stdarg.h>
#include <sys/types.h>
#include "../../include/my.h"

void print_hexa(va_list *list)
{
    my_putstr(hexa_mayus(va_arg(*list, unsigned int)));
}

void print_hexamin(va_list *list)
{
    my_putstr(hexa_minus(va_arg(*list, unsigned int)));
}

void print_unsignednbr(va_list *list)
{
    my_put_unsigned_nbr(va_arg(*list, unsigned int));
}
