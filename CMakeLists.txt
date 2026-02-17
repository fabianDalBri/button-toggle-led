cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(button-toggle-led C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

pico_sdk_init()

add_executable(button-toggle-led
    main.cpp
)

target_link_libraries(button-toggle-led pico_stdlib)
pico_add_extra_outputs(button-toggle-led)
