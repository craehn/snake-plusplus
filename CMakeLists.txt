cmake_minimum_required(VERSION 3.6)
project(Oppgaven)

set(CMAKE_CXX_STANDARD 11)

link_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES
        SDL2_Standardproject/SDL/SDLBmp.cpp
        SDL2_Standardproject/SDL/SDLBmp.h
        SDL2_Standardproject/SDL/SDLError.cpp
        SDL2_Standardproject/SDL/SDLError.h
        SDL2_Standardproject/SDL/SDLManager.cpp
        SDL2_Standardproject/SDL/SDLManager.h
        SDL2_Standardproject/SDL/SDLMath.h
        SDL2_Standardproject/SDL/SDLWindow.h
        SDL2_Standardproject/GameManager.cpp
        SDL2_Standardproject/GameManager.h
        SDL2_Standardproject/InputManager.cpp
        SDL2_Standardproject/InputManager.h
        SDL2_Standardproject/Main.cpp
        SDL2_Standardproject/resource.h
        SDL2_Standardproject/Timer.cpp
        SDL2_Standardproject/Timer.h)

add_executable(Oppgaven ${SOURCE_FILES})
