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
#include <filesystem>
#include "utility/utils.hpp"
#include "utility/dbg_console.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Ark/Ark.hpp"


#include "main/Game.hpp"


void setup_working_directory()
{
    // Get executable path
    std::string path = std::filesystem::current_path().generic_string();
    // Remove the build directory, so that we land on appropriate directory for asset loading
    std::vector<std::string> strList;
    strList.push_back("/build/code");
    strList.push_back("/vsbuild/code");
    strList.push_back("Release");
    strList.push_back("RelWithDebInfo");
    strList.push_back("Debug");
    utility::eraseSubStrings(path, strList);
    // Set a proper working directory
    std::filesystem::current_path(path);
}

void setup_logging()
{
    std::shared_ptr<spdlog::logger> m_pxllogger;

    std::string logfile_name = "log/oldschool.txt";

    // Remove old log file
    if(std::filesystem::exists(logfile_name))
    {
        std::remove(logfile_name.c_str());
    }

	// Create console sink and file sink
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logfile_name, true);
	spdlog::sinks_init_list sink_list = { file_sink, console_sink };
	// Make the logger use both the console and the file sink
    m_pxllogger = std::make_shared<spdlog::logger>("multi_sink", spdlog::sinks_init_list({console_sink, file_sink}));
	// Set the standard logger so that we can use it freely everywhere
    spdlog::set_default_logger(m_pxllogger);
	// Set the format pattern - [Loglevel] [Function] [Line] message
	spdlog::set_pattern("[%l] [%!] [line %#] %v");
}

int main(int, char**)
{
    setup_working_directory();
    utility::createConsoleWindow();
    setup_logging();

	SPDLOG_INFO("Oldschool initializing.");

    // A state can be shared by multiple virtual machines (note that they will NEVER modify it)
    // leave constructor empty to select the default standard library (loaded from an environment variable $ARKSCRIPT_PATH/lib)
    Ark::State state;

    // Will automatically compile the file if needed (if not, will take it from the ark cache)
    state.doString("(let foo (fun (x y) (+ x y 2)))");

    Ark::VM vm(state);
    vm.run();

    auto value = vm.call("foo", 5, 6.0);
    std::cout << value << "\n";  // displays 13

    Game game;

    if(game.init())
    {
        game.run();
    }

    utility::closeConsoleWindow();
    return 0;
}
