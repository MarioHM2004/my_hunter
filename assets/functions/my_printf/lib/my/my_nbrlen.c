/*
** EPITECH PROJECT, 2022
** my_nbrlen
** File description:
** counts and returns the number of characters
*/

int my_put_nbr(int nb);
char my_putchar(char c);

int my_nbrlen(long int num)
{
    int count = 0;

    if (num < 0)
        count = count +1;
    if (num == 0)
        count = count +1;
    while (num != 0) {
        num /= 10;
        count = count + 1;
    }
    return (count);
}

/*int main()
{
   my_put_nbr(my_nbrlen(-12344));
   int nb = printf("%d", -12344);
   printf("%d", nb);
    return(0);
}*/
