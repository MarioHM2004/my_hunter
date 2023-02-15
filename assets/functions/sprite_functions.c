/*
** EPITECH PROJECT, 2022
** sprite_functions.c
** File description:
** functions of game
*/

#include "../../include/structs.h"
#include "../../include/my.h"

void character_animation(duck_d *duck)
{
    if (duck->rect.left == 220) {
        duck->rect.left = 0;
    } else {
        duck->rect.left = duck->rect.left + 110;
    }
}

void move_sprite(duck_d *duck, button_d *button, window_d *screen)
{
    if (duck->position.x >= 1280) {
        button->is_end = true;
    } else{
        duck->position.x = duck->position.x + 1;
    }
}

void kill_duck(duck_d *duck, window_d *screen)
{
    int BxRight = sfSprite_getPosition(duck->duckSprite).x +110;
    int BxLeft = sfSprite_getPosition(duck->duckSprite).x;
    int ByDown = sfSprite_getPosition(duck->duckSprite).y +110;
    int ByUp = sfSprite_getPosition(duck->duckSprite).y;

    if (screen->event.mouseButton.x <= BxRight && screen->event.mouseButton.x
        >= BxLeft && screen->event.mouseButton.y <= ByDown &&
        screen->event.mouseButton.y >= ByUp){
        duck->counter++;
        my_printf("Score= %d\n", duck->counter);
        duck->position.x = -150;
        duck->position.y = rand() % 690;
    }
}

void render_duck(duck_d *duck, timer_d *time_lapse,
    window_d *screen, button_d *button)
{
    if (screen->is_game == true){
        sfSprite_setTextureRect(duck->duckSprite, duck->rect);
        sfSprite_setPosition(duck->duckSprite, duck->position);
        time_lapse->time = sfClock_getElapsedTime(time_lapse->clock);
        time_lapse->seconds = time_lapse->time.microseconds / 100000.0;

        if (time_lapse->seconds > .5){
            move_sprite(duck, button, screen);
        }
        if (time_lapse->seconds > 1) {
            character_animation(duck);
            sfClock_restart(time_lapse->clock);
        }
        sfSprite_setTexture(duck->duckSprite, duck->duckTexture, sfFalse);
        sfRenderWindow_drawSprite(screen->create_window,
            duck->duckSprite, NULL);
    }
}

void render_background(duck_d *duck, window_d *screen)
{
    sfSprite_setTexture(duck->Background, duck->BackgroundTexture, sfFalse);
    sfRenderWindow_drawSprite(screen->create_window,
        duck->Background, NULL);
}
