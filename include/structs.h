/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** functions prototypes
*/

#ifndef WINDOW_W
    #define WINDOW_W
    #include <SFML/Audio/Types.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System.h>
    #include <SFML/System/Time.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Audio/Music.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>

typedef struct window_w {

    sfVideoMode screen_size;
    sfRenderWindow *create_window;
    sfEvent event;
    bool is_game;

}window_d;

typedef struct duck_k {

    sfIntRect rect;
    sfTexture *duckTexture;
    sfTexture *BackgroundTexture;
    sfSprite *duckSprite;
    sfSprite *Background;
    sfVector2f position;
    int counter;

}duck_d;

typedef struct button_m {
    sfFont *font;
    sfText *TittleText;
    sfText *PlayText;
    sfText *QuitText;
    sfText *EndText;
    sfText *retryText;
    sfVector2f TittlePos;
    sfVector2f PlayPos;
    sfVector2f QuitPos;
    sfVector2f EndPos;
    sfVector2f retryPos;
    bool is_end;


}button_d;

typedef struct timer_r {

    sfTime time;
    sfClock *clock;
    float seconds;

}timer_d;

typedef struct global {

    window_d *screen;
    duck_d *duck;
    button_d *button;
    timer_d *time_lapse;

}global_d;

#endif
