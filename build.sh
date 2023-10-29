#!/bin/bash

mosquitto_build_config=""
mosquitto_build_config+=" -DDOCUMENTATION=OFF"
mosquitto_build_config+=" -DWITH_WEBSOCKETS=OFF"
mosquitto_build_config+=" -DWITH_STATIC_LIBRARIES=ON"
mosquitto_build_config+=" -DWITH_SRV=OFF"
mosquitto_build_config+=" -DWITH_BUNDLED_DEPS=ON"
mosquitto_build_config+=" -DWITH_TLS=OFF"
mosquitto_build_config+=" -DWITH_LIB_CPP=ON"

build_dir="build"

cmake -S . -B $build_dir $mosquitto_build_config
cmake --build $build_dir
