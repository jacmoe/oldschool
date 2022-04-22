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
cmake_minimum_required(VERSION 3.7)

project(oldschool)

if(WIN32)
    message(SEND_ERROR "This CMake script is meant to be used on Linux. And you are not on Linux at the moment. Use the Visual Studio solution instead :)")
endif(WIN32)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Allegro5 REQUIRED)

set(ARK_BUILD_EXE On)
add_subdirectory(3rdparty/Ark)

set(3RD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)
set(ARK_INCLUDE_DIR ${3RD_PARTY_DIR}/Ark/include)
set(ARK_STRING_INCLUDE_DIR ${3RD_PARTY_DIR}/Ark/lib/String/include)
set(SPDLOG_INCLUDE_DIR ${3RD_PARTY_DIR}/spdlog/include)

include_directories(
    ${ALLEGRO_INCLUDE_DIR}
    ${3RD_PARTY_DIR}
    ${SPDLOG_INCLUDE_DIR}
    ${ARK_INCLUDE_DIR}
    ${ARK_STRING_INCLUDE_DIR}
    ./code
)

add_subdirectory(code)
