add_executable(client 
    main.cpp
    client.cpp
    rpiLedController.cpp
)

target_include_directories(client PUBLIC inc)
target_include_directories(client PRIVATE .)

target_link_libraries(client common ws2811 mosquittopp_static)
