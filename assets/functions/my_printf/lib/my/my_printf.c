/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** creating printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/print.h"
#include "../../include/my.h"

int print_char(va_list *list);
int print_str(va_list *list);
int print_nbr(va_list *list);
int print_porcentage(va_list *list);
int print_oct(va_list *list);
int print_hexa(va_list *list);
int print_hexamin(va_list *list);
int print_unsignednbr(va_list *list);

print_t *flags_list(print_t *flag)
{
    flag[6].let = 'x';
    flag[6].pt = &print_hexamin;
    flag[7].let = 'X';
    flag[7].pt = &print_hexa;
    flag[8].let = 'u';
    flag[8].pt = &print_unsignednbr;
    return flag;
}

print_t *fill_flags(print_t *flag)
{
    flag[0].let = 'c';
    flag[0].pt = &print_char;
    flag[1].let = 's';
    flag[1].pt = &print_str;
    flag[2].let = 'd';
    flag[2].pt = &print_nbr;
    flag[3].let = 'i';
    flag[3].pt = &print_nbr;
    flag[4].let = '%';
    flag[4].pt = &print_porcentage;
    flag[5].let = 'o';
    flag[5].pt = &print_oct;
    flags_list(flag);
    return flag;
}

int my_flags(int index, va_list *list, const char *format)
{
    int index_two = 0;
    print_t flags[10];
    fill_flags(flags);

    while (index_two < 10) {
        if (flags[index_two].let == format[index +1]){
            return (flags[index_two].pt(list));
        }
        index_two = index_two +1;
    }
    index = index +1;
    return (0);
}

int my_printf(const char *format , ...)
{
    int index = 0;
    int len = 0;
    int n = 0;
    va_list list;
    va_start(list, format);

    while (format[index] != '\0') {
        if (format[index] == '%'){
            len = len + my_flags(index, &list, format);
            index = index +1;
        } else {
            my_putchar(format[index]);
            n = n +1;
        }
        index = index +1;
    }
    len = len + n;
    va_end(list);
    return (len);
}
