/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** function that reverses a string
*/

int my_strlen(char const *str);
char *my_revstr ( char *str )
{
    int index = 0;
    int length = my_strlen(str);
    char temp;
    while (index < length / 2){
        temp = str[index];
        str[index] = str[length - index -1];
        str[length - index -1] = temp;
        index = index + 1;
    }
    return (str);
}
