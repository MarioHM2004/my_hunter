/*
** EPITECH PROJECT, 2022
** sprite_functions.c
** File description:
** functions of game
*/

#include "../../include/structs.h"
#include "../../include/my.h"

void game_over(button_d *button, window_d *screen)
{
    if (button->is_end == true){
        sfText_setFont(button->EndText, button->font);
        sfText_setCharacterSize(button->EndText, 64);
        sfText_setColor(button->EndText, sfBlack);
        sfText_setPosition(button->EndText, button->EndPos);
        sfText_setString(button->EndText, "GAME OVER");

        sfRenderWindow_drawText(screen->create_window,
                                button->EndText, NULL);
        text(button, button->retryText, button->retryPos, "TRY AGAIN");
        sfRenderWindow_drawText(screen->create_window, button->retryText, NULL);
    }
}

void play_again(button_d *button, window_d *screen,
    duck_d *duck)
{
    int BxRight = sfText_getPosition(button->retryText).x +100;
    int BxLeft = sfText_getPosition(button->retryText).x;
    int ByDown = sfText_getPosition(button->retryText).y +30;
    int ByUp = sfText_getPosition(button->retryText).y;

    if (screen->event.mouseButton.x <= BxRight && screen->event.mouseButton.x
        >= BxLeft && screen->event.mouseButton.y <= ByDown &&
        screen->event.mouseButton.y >= ByUp){
        duck->position.x = 0;
        button->is_end = false;
        duck->counter = 0;
    }
}
