cmake_minimum_required(VERSION 3.8)

set(This Client)

set(HEADERS
    include/client/Enemy.h
    include/client/Game.h
    include/client/Network.h
    include/client/Player.h
)

set(SOURCES
    src/Enemy.cpp
    src/Game.cpp
    src/Network.cpp
    src/Player.cpp
    src/main.cpp
)

# Linking SFML API.
include_directories(${SFML}/include)
link_directories(${SFML}/lib)

add_executable(${This} ${SOURCES} ${HEADERS})

target_link_libraries(${This} PUBLIC
    sfml-graphics-d
    sfml-audio-d
    sfml-network-d
    sfml-window-d
    sfml-system-d
)

target_include_directories(${This} PUBLIC include)

set_target_properties(${This} PROPERTIES
    FOLDER Networking/Client
)
