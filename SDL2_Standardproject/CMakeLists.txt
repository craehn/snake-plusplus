project(SDL2_Standardproject)

#set(HEADER_FILES
#        SDL/SDLBmp.h
#        SDL/SDLError.h
#        SDL/SDLManager.h
#        SDL/SDLMath.h
#        SDL/SDLWindow.h
#        GameManager.h
#        InputManager.h
#        resource.h
#        Timer.h
#        GameData.h
#        Point2D.h
#        GameObject.h
#        Snake.h
#        )
file(GLOB HEADER_FILES "*.h" "SDL/*.h")
#        SDL2_Standardproject/Assets/gfx/sdl2.bmp
#        SDL2_Standardproject/Assets/gfx/Apple_v1.bmp
#        SDL2_Standardproject/Assets/gfx/SnakeBody_v1.bmp
#        SDL2_Standardproject/Assets/gfx/SnakeHead_v1.bmp
#        SDL2_Standardproject/Assets/gfx/sdl_bro.bmp
#        SDL2_Standardproject/Assets/gfx/treasure.bmp
#set(SOURCE_FILES
#        SDL/SDLBmp.cpp
#        SDL/SDLError.cpp
#        SDL/SDLManager.cpp
#        Timer.cpp
#        GameManager.cpp
#        InputManager.cpp
#        GameData.cpp
#        Point2D.cpp
#        GameObject.cpp
#        Snake.cpp
#        )

file(GLOB SOURCE_FILES "*.cpp" "SDL/*.cpp")







add_library(SDL2_Standardproject STATIC ${SOURCE_FILES} ${HEADER_FILES})