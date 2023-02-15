##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles your libmy
##

SRC  =          ./

OBJ  =          $(SRC.c=.o)

NAME =          my_hunter

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -c assets/functions/my_printf/lib/my/*.c
	ar rc assets/functions/my_printf/lib/my/printf.a *.o
	cp assets/functions/my_printf/lib/my/printf.a ./
	gcc -o $(NAME) -Wall -Werror  main.c assets/functions/*.c printf.a \
	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio
	make clean

clean:
	rm -f *.o

fclean:
	make clean
	rm -f assets/functions/my_printf/lib/my/printf.a
	rm -f printf.a
	rm -f $(NAME)

re : fclean all
