cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico_w)
# Always include it
include(pico_sdk_import.cmake)

# Project's name
project(HelloAndBlink)

# SDK Initialization - Mandatory
pico_sdk_init()

# C/C++ project files
add_executable(HelloAndBlink
    helloandblink.c getvalue.c
)

# pico_stdlib library. You can add more if they are needed
target_link_libraries(HelloAndBlink pico_stdlib)

# Enable usb output, disable uart output
pico_enable_stdio_usb(HelloAndBlink 1)
pico_enable_stdio_uart(HelloAndBlink 0)

# Need to generate UF2 file for upload to RP2040
pico_add_extra_outputs(HelloAndBlink)