/**
 * @file Constants.hpp
 * @author Alexandre Plateau (lexplt.dev@gmail.com)
 * @brief Constants used by ArkScript
 * @version 0.1
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef INCLUDE_ARK_CONSTANTS_HPP_IN
#define INCLUDE_ARK_CONSTANTS_HPP_IN

// clang-format off
constexpr int ARK_VERSION_MAJOR = 3;
constexpr int ARK_VERSION_MINOR = 2;
constexpr int ARK_VERSION_PATCH = 0;
// clang-format on
constexpr int ARK_VERSION = (ARK_VERSION_MAJOR << 16) + (ARK_VERSION_MINOR << 8) + ARK_VERSION_PATCH;
constexpr char ARK_VERSION_STR[4] = { ARK_VERSION_MAJOR + '0', ARK_VERSION_MINOR + '0', ARK_VERSION_PATCH + '0', 0x00 };

#define ARK_COMPILATION_OPTIONS ""
#define ARK_COMPILER "Clang"
#define ARK_CACHE_DIRNAME "__arkscript__"
#define ARK_NO_NAME_FILE "FILE"

#if defined(_WIN32) || defined(_WIN64)
#    define ARK_PLATFORM_NAME "Windows"
#elif defined(__APPLE__) || defined(__MACH__)
#    define ARK_PLATFORM_NAME "Mac OSX"
#elif defined(__linux__)
#    define ARK_PLATFORM_NAME "Linux"
#elif defined(__FreeBSD__)
#    define ARK_PLATFORM_NAME "FreeBSD"
#elif defined(__unix) || defined(__unix__)
#    define ARK_PLATFORM_NAME "Unix"
#else
#    define ARK_PLATFORM_NAME "Other"
#endif

#include <cinttypes>
#include <cstddef>

namespace Ark
{
    // Compiler options
    constexpr uint16_t FeatureRemoveUnusedVars = 1 << 4;

    // Default features for the VM x Compiler x Parser
    constexpr uint16_t DefaultFeatures = FeatureRemoveUnusedVars;

    constexpr std::size_t VMStackSize = 8192;
}

#endif
