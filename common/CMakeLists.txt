add_library(common STATIC mqttCommunicator.cpp)

target_include_directories(common PUBLIC inc)
# include directories used by eclipse mosquitto 
target_include_directories(common
    PRIVATE
        ${mosquitto_SOURCE_DIR}
		${mosquitto_SOURCE_DIR}/include
        ${mosquitto_SOURCE_DIR}/lib
        ${mosquitto_SOURCE_DIR}/lib/cpp
		${STDBOOL_H_PATH}
        ${STDINT_H_PATH}
		${OPENSSL_INCLUDE_DIR}
        ${PTHREAD_INCLUDE_DIR}
)
target_link_libraries(common libmosquitto_static)
