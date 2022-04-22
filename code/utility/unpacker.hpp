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

// Taken from Steve Jessop's answer to the question
// "C/C++ packing signed char into int" at https://stackoverflow.com/a/2438565/1795121

namespace utility
{
    template <int N>
    uint8_t unpack_u(uint32_t packed) {
        // cast to avoid potential warnings for implicit narrowing conversion
        return static_cast<uint8_t>(packed >> (N*8));
    }

    template <int N>
    int8_t unpack_s(uint32_t packed) {
        uint8_t r = unpack_u<N>(packed);
        return (r <= 127 ? r : r - 256); // thanks to caf
    }
}
