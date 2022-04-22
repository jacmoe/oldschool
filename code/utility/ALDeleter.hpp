/*# This file is part of the
#  _____ _     _          _                 _ 
# |  _  | |   | |        | |               | |
# | | | | | __| |___  ___| |__   ___   ___ | |
# | | | | |/ _` / __|/ __| '_ \ / _ \ / _ \| |
# \ \_/ / | (_| \__ \ (__| | | | (_) | (_) | |
#  \___/|_|\__,_|___/\___|_| |_|\___/ \___/|_|
#                                             
#   project
#
#   https://github.com/jacmoe/oldschool
#
#   (c) 2020 - 2022 Jacob Moena
#
#   MIT License
#*/
#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

namespace utility {
    struct ALDeleter
    {
        void operator()(ALLEGRO_CONFIG* config) { al_destroy_config(config); }
        void operator()(ALLEGRO_DISPLAY* display) { al_destroy_display(display); }
        void operator()(ALLEGRO_TIMER* timer) { al_destroy_timer(timer); }
        void operator()(ALLEGRO_EVENT_QUEUE* eventqueue) { al_destroy_event_queue(eventqueue); }
        void operator()(ALLEGRO_FONT* font) { al_destroy_font(font); }
        void operator()(ALLEGRO_BITMAP* bitmap) { al_destroy_bitmap(bitmap); }
    };
}
