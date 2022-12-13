find_package(jsoncpp CONFIG REQUIRED)
file (GLOB SOURCE Algos/*.cpp UI/*.cpp main.cpp)
include_directories(Include "C:/Users/madonna/Compilable/vcpkg/installed/x86-windows/include")

add_executable(main ${SOURCE})

target_link_libraries(main PRIVATE jsoncpp_lib jsoncpp_object JsonCpp::JsonCpp)
