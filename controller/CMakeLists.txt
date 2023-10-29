
add_executable(controller main.cpp controller.cpp)
target_include_directories(controller PUBLIC inc)

# include directories used by eclipse mosquitto 
target_include_directories(controller
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
target_link_libraries(controller common mosquittopp_static)
