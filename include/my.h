/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** functions prototypes
*/

#ifndef MY_H
    #define MY_H
    #include "structs.h"

int my_strcmp ( char const *s1 , char const *s2 );

char *my_revstr ( char *str );

int my_putstr(char const *str);

int my_put_nbr(int nb);

void my_putchar(char c);

int my_strlen(char const *str);

int oct(unsigned int n);

char *hexa_mayus(unsigned int n);

char *hexa_minus(unsigned int n);

int my_put_unsigned_nbr(unsigned int nb);

int my_nbrlen(int num);

int my_printf(const char *format , ...);

void init_window(window_d *w);

void init_character(duck_d *d);

void init_timer(timer_d *t);

void character_animation(duck_d *duck);

void move_sprite(duck_d *duck, button_d *button, window_d *screen);

void kill_duck(duck_d *duck, window_d *screen);

void render_duck(duck_d *duck, timer_d *time_lapse,
    window_d *screen, button_d *button);

void render_background(duck_d *duck, window_d *screen);

void init_menu(button_d *b);

void text(button_d *button, sfText *text, sfVector2f position, const char *str);

void menu(button_d *button, window_d *screen);

void play_game(button_d *button, window_d *screen,
    duck_d *duck);

void quit_game(button_d *button, window_d *screen);

void game_over(button_d *button, window_d *screen);

void play_again(button_d *button, window_d *screen,
    duck_d *duck);

#endif
