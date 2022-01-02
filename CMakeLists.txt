cmake_minimum_required(VERSION 3.13) # "target_link_options" was introuced in 3.13
cmake_policy(SET CMP0048 NEW) # For using VERSION in "project"

project(xmasdemo2021 VERSION 0.1 DESCRIPTION "AkinoSoft XMas Demo 2021!")
set(CMAKE_C_STANDARD 17)
#set(CMAKE_CXX_STANDARD 11)


# Adding Raylib
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_MakeAvailable(raylib)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/*.c") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/sources/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
if (WIN32)
    target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/sources/resources.rc")
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)


# Setting ASSETS_PATH
if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets/") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
endif()

#compile options
if (MSVC)
    # warning level 4 and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    # lots of warnings and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
#target_compile_features(${PROJECT_NAME} PRIVATE c_std_17)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 17)

#Link options for Windows Release
# Use this code:

# #ifdef _WIN32
# #ifndef _DEBUG
# int WinMain(void) {
# #else
# int main(void) {
# #endif
# #else
# int main(void) {
# #endif

if (CMAKE_BUILD_TYPE MATCHES Release)
    if (WIN32)
        if (MSVC)
            target_link_options(${PROJECT_NAME} PRIVATE /SUBSYSTEM:WINDOWS)
        else()
            target_link_options(${PROJECT_NAME} PRIVATE -mwindows)
        endif()
    endif()
endif()

#Color on output for GCC and Clang (Does not work with ninja)
if (CMAKE_CXX_COMPILER_ID STREQUAL GNU)
    target_compile_options (${PROJECT_NAME} PRIVATE -fdiagnostics-color=always)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    target_compile_options (${PROJECT_NAME} PRIVATE -fcolor-diagnostics)
endif ()
