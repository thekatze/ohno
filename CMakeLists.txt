cmake_minimum_required(VERSION 3.28)

# not best practice but this is just a hobby project
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# allow dawn python stuff
cmake_policy(SET CMP0148 OLD)

project(
    ohno
    VERSION 0.1.0 # any version number
    LANGUAGES CXX
)

set(DAWN_FETCH_DEPENDENCIES ON)
add_subdirectory(dependencies/dawn EXCLUDE_FROM_ALL)

add_executable(ohno main.cpp)
target_include_directories(ohno PRIVATE DAWN_INCLUDE_DIR)
target_link_libraries(ohno PRIVATE webgpu_cpp webgpu_dawn webgpu_glfw)

set_property(TARGET ohno PROPERTY CXX_STANDARD 23)

if (MSVC)
    target_compile_options(ohno PRIVATE /W4)
else()
    target_compile_options(ohno PRIVATE -fmodules -Wall -Wextra -pedantic)
endif()

