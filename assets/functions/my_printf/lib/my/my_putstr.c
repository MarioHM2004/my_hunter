/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displays one-by-one the characters of a string
*/
#include<unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int index = 0;

    while (str[index] != '\0'){
        index = index + 1;
    }
    write(1, str, index);
    return (my_strlen(str));
}
