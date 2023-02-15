/*
** EPITECH PROJECT, 2022
** print.h
** File description:
** struct
*/

#include <stdarg.h>

#ifndef STRUCT_T
    #define STRUCT_T

typedef struct print_t {
    char let;
    int (*pt)(va_list *);
} print_t;

#endif
