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
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

namespace utility
{
  /*
  * Erase all Occurrences of given substring from main string.
  * Lifted from https://thispointer.com/how-to-remove-substrings-from-a-string-in-c/
  */
  void eraseAllSubStr(std::string & mainStr, const std::string & toErase);

  /*
  * Erase all Occurrences of all given substrings from main string using C++11 stuff
  * Lifted from https://thispointer.com/how-to-remove-substrings-from-a-string-in-c/
  */
  void eraseSubStrings(std::string & mainStr, const std::vector<std::string> & strList);
}
