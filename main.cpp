#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    al_set_window_title(display, "Allegro5 Window");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    bool running = true;
    while (running)
    {
        ALLEGRO_EVENT ev;
        while (al_get_next_event(queue, &ev))
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                running = false;
            if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
            {
                al_acknowledge_resize(display);
            }
        }

        al_clear_to_color(al_map_rgba_f(0.25, 0.25, 0.25, 1));
        al_flip_display();
    }

    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}
