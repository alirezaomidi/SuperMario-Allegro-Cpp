#include "gamescreen.h"
#include "inputmanager.h"
#include "soundmanager.h"

#include <allegro5/allegro_native_dialog.h>

int main() {
    const float FPS = 60.0f;

    if (!al_init()) {
        al_show_native_message_box(NULL, "Error", "Error", "Cannot initialize Allegro", NULL, NULL);
        return -1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!display) {
        al_show_native_message_box(NULL, "Error", "Error", "Cannot create display", NULL, NULL);
        return -1;
    }

    al_install_keyboard();

    al_init_image_addon();
    al_init_acodec_addon();
    al_install_audio();

    ALLEGRO_TIMER *timer = al_create_timer(1.0f / FPS);
    ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();

    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_display_event_source(display));

    bool done = false;

    InputManager input;
    SoundManager sound;
    GameScreen game(&sound);

    sound.playTheme();

    al_start_timer(timer);

    while (!done) {
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);

        if (input.isKeyPressed(event, ALLEGRO_KEY_ESCAPE) || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            done = true;

        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (event.timer.source == timer) {
                game.checkCollides();
                al_clear_to_color(al_map_rgb(107, 140, 255));
                game.draw();
                al_flip_display();
            }
        }
        game.update(event);
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(eventQueue);

    return 0;
}
