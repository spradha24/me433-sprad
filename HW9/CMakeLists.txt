cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(HW9 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(NICK_PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

# Add multi example
add_subdirectory(zp)

target_include_directories(zp PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR} # Include the current source directory
    /Users/siddp/Pico/pico-sdk/src/rp2040/hardware_regs/hardware # Include the path to spi.h
    /Users/siddp/Pico/pico-sdk/src/rp2040/hardware_structs/hardware # Include the path to spi.h
)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )