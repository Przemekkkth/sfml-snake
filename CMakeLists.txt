cmake_minimum_required(VERSION 3.28)
project(SFML_SNAKE LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main
    src/BaseState.h
    src/Game.cpp
    src/Game.h
    src/Globals.h
    src/Main.cpp
    src/SharedContext.h
    src/Snake.cpp
    src/Snake.h
    src/StateGame.cpp
    src/StateGame.h
    src/StateIntro.cpp
    src/StateIntro.h
    src/StateManager.cpp
    src/StateManager.h
    src/StatePause.cpp
    src/StatePause.h
    src/TextBox.cpp
    src/TextBox.h
    src/Window.cpp
    src/Window.h
    src/World.cpp
    src/World.h
)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)
