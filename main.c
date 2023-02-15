/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main structure
*/

#include "include/my.h"
#include "include/structs.h"
#include <SFML/Audio/Music.h>

void analyse_events(duck_d *duck, window_d *screen,
                    button_d *button, timer_d *time_lapse)
{
    while (sfRenderWindow_pollEvent(screen->create_window, &screen->event)) {
        if (screen->event.type == sfEvtClosed) {
            sfRenderWindow_close(screen->create_window);
        }
        if (screen->event.type == sfEvtMouseButtonPressed) {
            kill_duck(duck, screen);
            screen->is_game == false ?
                quit_game(button, screen) : 0;
            screen->is_game == false ?
                play_game(button, screen, duck) : 0;
            play_again(button, screen, duck);
        }
    }
}

int game_loop(window_d *screen, duck_d *duck,
    timer_d *time_lapse, button_d *button)
{
    if (screen->create_window == NULL || duck->duckTexture == NULL ||
        duck->duckSprite == NULL || duck->BackgroundTexture == NULL ||
        duck->Background == NULL)
        return (EXIT_FAILURE);
    while (sfRenderWindow_isOpen(screen->create_window)) {
        render_background(duck, screen);
        render_duck(duck, time_lapse, screen, button);
        menu(button, screen);
        game_over(button, screen);
        analyse_events(duck, screen, button, time_lapse);
        sfRenderWindow_display(screen->create_window);
        sfRenderWindow_clear(screen->create_window, sfBlack);
    }
    return 0;
}

void destroy_all(window_d *screen, duck_d *duck,
    timer_d *time_lapse, button_d *button)
{
    sfRenderWindow_destroy(screen->create_window);
    sfSprite_destroy(duck->duckSprite);
    sfSprite_destroy(duck->Background);
    sfTexture_destroy(duck->duckTexture);
    sfTexture_destroy(duck->BackgroundTexture);
    sfText_destroy(button->PlayText);
    sfText_destroy(button->TittleText);
    sfText_destroy(button->QuitText);
}

void game_description(void)
{
    my_putstr("DUCK HUNT\nHow to play:\n"
    "click on the duck with the mouse to kill him.\n");
}

int main(int ac, char *av[])
{
    window_d screen;
    duck_d duck;
    timer_d time_lapse;
    button_d button;
    if (av[1] == NULL){
        init_window(&screen);
        init_character(&duck);
        init_timer(&time_lapse);
        init_menu(&button);
        game_loop(&screen, &duck, &time_lapse, &button);
        destroy_all(&screen, &duck, &time_lapse, &button);
    } else if (my_strcmp("-h", av[1]) == 0){
        game_description();
    }
}
