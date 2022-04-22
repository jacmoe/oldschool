# This file is part of the
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
#

#
# Used to generate Visual Studio projects on Windows that can then be added to the PixelWolf solution
#

cmake_minimum_required(VERSION 3.7)

project(pixelwolf_deps)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Ark)

# add_subdirectory(physfs)
