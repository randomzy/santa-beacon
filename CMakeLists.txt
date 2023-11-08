cmake_minimum_required(VERSION 3.10)
project(christmass-lights)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(client)
add_subdirectory(controller)
add_subdirectory(common)

include(FetchContent)

FetchContent_Declare(
    mosquitto
    GIT_REPOSITORY https://github.com/randomzy/mosquitto.git
    GIT_TAG 328eb6e75962c98ff9d4d4d804d2021b4a3620f6
)
set(DOCUMENTATION         OFF CACHE INTERNAL "")
set(WITH_CLIENTS          OFF CACHE INTERNAL "")
set(WITH_BROKER           OFF CACHE INTERNAL "")
set(WITH_APPS             OFF CACHE INTERNAL "")
set(WITH_PLUGINS          OFF CACHE INTERNAL "")

set(WITH_WEBSOCKETS       OFF CACHE INTERNAL "")
set(WITH_STATIC_LIBRARIES ON  CACHE INTERNAL "")
set(WITH_SRV              OFF CACHE INTERNAL "")
set(WITH_BUNDLED_DEPS     ON  CACHE INTERNAL "")
set(WITH_TLS              OFF CACHE INTERNAL "")
set(WITH_LIB_CPP          ON  CACHE INTERNAL "")
FetchContent_MakeAvailable(mosquitto)

FetchContent_Declare(
    rpi_ws281x
    GIT_REPOSITORY https://github.com/randomzy/rpi_ws281x.git
    GIT_TAG 3be8495f337e0ba3c75d90f6c73b0d22f9c9ebf9
)

FetchContent_MakeAvailable(rpi_ws281x)
