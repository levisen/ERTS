cmake_minimum_required(VERSION 3.16)
project(sample_process_ex)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH $ENV{SYSTEMC_HOME})

include_directories(${CMAKE_PREFIX_PATH}/include)
find_package(SystemCLanguage CONFIG REQUIRED)
link_directories(${CMAKE_PREFIX_PATH}/lib)
add_executable(exec main.cpp simple_process_ex.cpp)
target_link_libraries(exec SystemC::systemc)