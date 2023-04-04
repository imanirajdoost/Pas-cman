cmake_minimum_required(VERSION 3.7)

project(PacMan LANGUAGES CXX)

add_compile_options(-gdwarf-4)


find_package(SDL2 REQUIRED)


include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS
		"${PROJECT_SOURCE_DIR}/src/*.h"
		"${PROJECT_SOURCE_DIR}/src/header/*.h"
		"${PROJECT_SOURCE_DIR}/src/header/controller/*.h"
		"${PROJECT_SOURCE_DIR}/src/header/model/*.h"
		"${PROJECT_SOURCE_DIR}/src/header/model/component/*.h"
		"${PROJECT_SOURCE_DIR}/src/header/model/eatable/*.h"
		"${PROJECT_SOURCE_DIR}/src/header/view/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/cpp/*.cpp"
		"${PROJECT_SOURCE_DIR}/src/cpp/controller/*.cpp"
		"${PROJECT_SOURCE_DIR}/src/cpp/model/*.cpp"
		"${PROJECT_SOURCE_DIR}/src/cpp/model/component/*.cpp"
		"${PROJECT_SOURCE_DIR}/src/cpp/model/eatable/*.cpp"
		"${PROJECT_SOURCE_DIR}/src/cpp/view/*.cpp"
        )

#file(GLOB_RECURSE SRCS *.cpp)
#file(GLOB_RECURSE SRCS *.h)

add_executable(${PROJECT_NAME} ${SRCS})

target_sources(${PROJECT_NAME} PRIVATE pacman.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pacman_sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

IF (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
ENDIF()
