/*
** EPITECH PROJECT, 2022
** button.c
** File description:
** play/end
*/

#include "../../include/structs.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <stdbool.h>

void text(button_d *button, sfText *text, sfVector2f position, const char *str)
{
    sfText_setFont(text, button->font);
    sfText_setCharacterSize(text, 24);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    sfText_setString(text, str);
}

void menu(button_d *button, window_d *screen)
{
    if (screen->is_game == false){
        sfText_setFont(button->TittleText, button->font);
        sfText_setCharacterSize(button->TittleText, 64);
        sfText_setColor(button->TittleText, sfBlack);
        sfText_setPosition(button->TittleText, button->TittlePos);
        sfText_setString(button->TittleText, "DUCK HUNT");

        text(button, button->PlayText, button->PlayPos, "PLAY");
        text(button, button->QuitText, button->QuitPos, "QUIT");

        sfRenderWindow_drawText(screen->create_window,
                                button->TittleText, NULL);
        sfRenderWindow_drawText(screen->create_window,
                                button->PlayText, NULL);
        sfRenderWindow_drawText(screen->create_window,
                                button->QuitText, NULL);
    }
}

void play_game(button_d *button, window_d *screen,
    duck_d *duck)
{
    int BxRight = sfText_getPosition(button->PlayText).x +50;
    int BxLeft = sfText_getPosition(button->PlayText).x;
    int ByDown = sfText_getPosition(button->PlayText).y +30;
    int ByUp = sfText_getPosition(button->PlayText).y;

    if (screen->event.mouseButton.x <= BxRight && screen->event.mouseButton.x
        >= BxLeft && screen->event.mouseButton.y <= ByDown &&
        screen->event.mouseButton.y >= ByUp){
        screen->is_game = true;
    }
}

void quit_game(button_d *button, window_d *screen)
{
    int BxRight = sfText_getPosition(button->QuitText).x +50;
    int BxLeft = sfText_getPosition(button->QuitText).x;
    int ByDown = sfText_getPosition(button->QuitText).y +30;
    int ByUp = sfText_getPosition(button->QuitText).y;

    if (screen->event.mouseButton.x <= BxRight && screen->event.mouseButton.x
        >= BxLeft && screen->event.mouseButton.y <= ByDown &&
        screen->event.mouseButton.y >= ByUp){
        sfRenderWindow_close(screen->create_window);
    }
}
