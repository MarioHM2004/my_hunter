/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare two strings
*/

#include<unistd.h>

int my_strcmp (char const *s1, char const *s2)
{
    int index = 0;

    if (s1[index] > s2[index]){
        return 1;
    }
    if (s1[index] < s2[index]){
        return -1;
    }
    while ((s1[index] == s2[index]) && (s1[index]) && (s2[index]) && ++index);
    return (s1[index] - s2[index]);
}
