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
// Creates a console window for a Windows program
// It does nothing on Linux, but it is not needed since we are running in the console there anyway ;)
#ifdef _WIN32
#include <iostream>
#include <windows.h>
#include <fstream>
#include <streambuf>
#endif //_WIN32

namespace utility {
    void createConsoleWindow();
    void closeConsoleWindow();
}
