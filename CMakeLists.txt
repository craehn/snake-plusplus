cmake_minimum_required(VERSION 3.7)
project(snake-plusplus)

set(CMAKE_CXX_STANDARD 14)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/SDL2_Standardproject/source/headers)

set(SOURCE_FILES

        SDL2_Standardproject/Assets/gfx/sdl2.bmp
        SDL2_Standardproject/Assets/gfx/sdl_bro.bmp
        SDL2_Standardproject/Assets/gfx/treasure.bmp
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

add_executable(snake-plusplus ${SOURCE_FILES})
target_link_libraries(snake-plusplus ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})