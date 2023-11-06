add_executable(controller main.cpp controller.cpp)
target_include_directories(controller PUBLIC inc)

target_link_libraries(controller common mosquittopp_static)
