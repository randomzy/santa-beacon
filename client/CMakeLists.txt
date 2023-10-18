add_library(client client.cpp)
target_include_directories(client PUBLIC inc)
target_link_libraries(client common)
