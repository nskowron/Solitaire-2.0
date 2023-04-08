find_package(jsoncpp CONFIG REQUIRED)
file (GLOB SOURCE Algos/*.cpp UI/*.cpp main.cpp)
include_directories(Include)

add_executable(Solitaire ${SOURCE})

target_link_libraries(Solitaire jsoncpp)
