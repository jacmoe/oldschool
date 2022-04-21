# This file is part of the
# ██████╗ ██╗  ██╗██╗     ██╗    ██╗ ██████╗ ██╗     ███████╗
# ██╔══██╗╚██╗██╔╝██║     ██║    ██║██╔═══██╗██║     ██╔════╝
# ██████╔╝ ╚███╔╝ ██║     ██║ █╗ ██║██║   ██║██║     █████╗  
# ██╔═══╝  ██╔██╗ ██║     ██║███╗██║██║   ██║██║     ██╔══╝  
# ██║     ██╔╝ ██╗███████╗╚███╔███╔╝╚██████╔╝███████╗██║     
# ╚═╝     ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚══════╝╚═╝     
#   project
#
#   https://github.com/jacmoe/pxlwolf
#
#   (c) 2020 - 2022 Jacob Moena
#
#   MIT License
#
set(TARGET_NAME oldschool)

set(main
    ./main/Application.cpp
    ./main/Application.hpp
    ./main/Game.cpp
    ./main/Game.hpp
    ./main/Pixelator.cpp
    ./main/Pixelator.hpp
    ./main/types.hpp
)

set(utility
    ./utility/dbg_console.cpp
    ./utility/dbg_console.hpp
    ./utility/ImageAtlas.cpp
    ./utility/ImageAtlas.hpp
    ./utility/ALDeleter.hpp
    ./utility/utils.cpp
    ./utility/utils.hpp
    # ${3RD_PARTY_DIR}/lua_main.hpp
)

add_executable(${TARGET_NAME}
    ./main.cpp
    ${main}
    ${utility}
)

target_link_libraries(oldschool ${ALLEGRO_LIBRARIES} ArkReactor)
