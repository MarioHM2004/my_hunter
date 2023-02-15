/*
** EPITECH PROJECT, 2022
** init_strucs.c
** File description:
** initialize structs
*/

#include "../../include/structs.h"
#include "../../include/my.h"
#include <SFML/Graphics/Text.h>

void init_window(window_d *w)
{
    sfVideoMode video_mode = {1280, 800, 32};
    sfRenderWindow *window =
        sfRenderWindow_create(video_mode, "Screen 1", sfDefaultStyle, NULL);
    bool is_game = false;

    window_d screen = {
        .screen_size = video_mode,
        .create_window = window,
        .is_game = is_game};
    *w = screen;
}

void init_character(duck_d *d)
{
    sfIntRect dimensions = {0, 0, 110, 110};
    sfTexture *texture2 =
            sfTexture_createFromFile("assets/sprites/sea.jpg", NULL);
    sfTexture *texture =
            sfTexture_createFromFile("assets/sprites/bird.png", NULL);
    sfSprite *sprite2 = sfSprite_create();
    sfSprite *sprite = sfSprite_create();
    sfVector2f offset = {-200, 0};

    duck_d duck = {.rect = dimensions,
        .duckTexture = texture, .duckSprite = sprite,
        .BackgroundTexture = texture2, .Background = sprite2,
        .position = offset, .counter = 0};

    *d = duck;
}

void init_menu(button_d *b)
{
    sfFont *font = sfFont_createFromFile("assets/sprites/Mermaid Babies.otf");
    sfText *Tittletext = sfText_create();
    sfText *Playtext = sfText_create();
    sfText *QuitText = sfText_create();
    sfText *EndText = sfText_create();
    sfText *replayText = sfText_create();
    sfVector2f TittlePos = {480, 200};
    sfVector2f PlayPos = {600, 325};
    sfVector2f QuitPos = {600, 400};
    sfVector2f EndPos = {480, 200};
    sfVector2f replayPos = {600, 325};
    bool isEnd = false;

    button_d button = {.font = font, .is_end = isEnd,
                .TittleText = Tittletext, .PlayText = Playtext,
                .QuitText = QuitText, .EndText = EndText,
                .retryText = replayText, .EndPos = EndPos,
                .retryPos = replayPos, .TittlePos = TittlePos,
                .PlayPos = PlayPos, .QuitPos = QuitPos};
    *b = button;
}

void init_timer(timer_d *t)
{
    sfClock *clock = sfClock_create();

    timer_d time_lapse = {.clock = clock, .seconds = 0};
    *t = time_lapse;
}
