#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>

int Rotate_tri(int*, int*, int*, int*, int*, int*);

int main()
{
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY *s = al_create_display(800, 600);
    ALLEGRO_COLOR electricBlue = al_map_rgb(44, 117, 255);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    ALLEGRO_EVENT_SOURCE *keyboard = al_get_keyboard_event_source();
    al_register_event_source(event_queue, keyboard);

    bool done = false;
    int x = 10, y = 10, a=0, b=0, c=0;
    int movespeed = 5;

    //int state = NULL;

    while(!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);

        if(events.type = ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(events.keyboard.keycode)
            {
            case ALLEGRO_KEY_DOWN:
                if(y<600-500)
                y+=movespeed;
                break;
            case ALLEGRO_KEY_UP:
                if(y>-300)
                y-=movespeed;
                break;
            case ALLEGRO_KEY_RIGHT:
                if(x<800-500)
                x+=movespeed;
                break;
            case ALLEGRO_KEY_LEFT:
                if(x>-200)
                x-=movespeed;
                break;
            case ALLEGRO_KEY_R:
                a+=movespeed;
                //a-=movespeed;
                b-=movespeed;
                //b+=movespeed;
                c+=movespeed;
                //c-=movespeed;
                break;


            case ALLEGRO_KEY_E:
                a-=movespeed;
                //a+=movespeed;
                b+=movespeed;
                //b-=movespeed;
                c-=movespeed;
                //c+=movespeed;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
            }
        }


        al_draw_filled_triangle(x+a, y+a, x+b, y+a, x-b, y+b, al_map_rgb(0, 255, 0));
        al_flip_display();
        al_clear_to_color(al_map_rgb(70, 70, 70));
    }


    al_destroy_display(s);

    return 0;
}

