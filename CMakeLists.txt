cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME "Whisperer")
set(SRC_DIR src)
set(CMAKE_CXX_FLAGS "-std=c++11")

project(${PROJECT_NAME})

# Build executable
add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp)

# Include ASCIILib
add_subdirectory(ASCIILib)
include_directories(ASCIILib/ASCIILib)
target_link_libraries(${PROJECT_NAME} ASCIILib)

# Then find SDL
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Whisperer_SOURCE_DIR}/cmake")

# Include SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ${SDLMIXER_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
    )
target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDLMIXER_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    )

# Include source files recursively
file(GLOB_RECURSE Whisperer_src
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.cpp"
    )

add_library(source ${Whisperer_src})
target_link_libraries(${PROJECT_NAME} source)
