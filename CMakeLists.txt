cmake_minimum_required(VERSION 3.10)
project(christmass-lights)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(client)
add_subdirectory(controller)
add_subdirectory(common)

add_subdirectory(vendor/mosquitto)
add_subdirectory(vendor/rpi_ws281x)
