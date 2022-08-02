file (GLOB SOURCE Algos/*.cpp UI/*.cpp main.cpp)
include_directories(Include)

add_executable(main ${SOURCE})
