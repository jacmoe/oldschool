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

#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include "main/types.hpp"

namespace utility
{
    class ImageAtlas
    {
    public:
        ImageAtlas();
        ~ImageAtlas();

        bool load(const std::string& path, Vector2i tile_size);

        inline const Vector2i getTileSize() { return { m_width, m_height }; }
        inline const int getCols() { return m_cols; }
        inline const int getRows() { return m_rows; }

        uint8_t* getPixels(int index) { return &m_buffers[index].pixels[0]; }
        ALLEGRO_COLOR getPixel(int index, int x, int y);

    private:
        struct Buffer
        {
            std::vector<uint8_t> pixels;
            uint32_t width;
            uint32_t height;
        };
        std::vector<Buffer> m_buffers;
        int m_rows;
        int m_cols;
        int m_width;
        int m_height;
    };
}
