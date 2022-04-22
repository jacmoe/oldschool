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
#include "dbg_console.hpp"
#ifdef _WIN32
#include <io.h>
#endif
namespace utility {
#ifdef _WIN32
int _hConsole;

void createConsoleWindow()
{
    AllocConsole();
    FILE *fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
}

void closeConsoleWindow()
{
    _close(_hConsole);
}
#else
void createConsoleWindow()
{
}

void closeConsoleWindow()
{
}

#endif //_WIN32
}
