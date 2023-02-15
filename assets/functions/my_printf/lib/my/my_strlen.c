/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** counts and returns the number of characters
*/
int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index = index + 1;
    }
    return (index);
}
