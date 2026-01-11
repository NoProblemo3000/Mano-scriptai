
cmake_minimum_required(VERSION 3.16)
project(45-SolarWinds-Maintenance-Window LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(45-SolarWinds-Maintenance-Window
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(45-SolarWinds-Maintenance-Window PRIVATE include)

# Tests (paprastas test runneris)
add_executable(45-SolarWinds-Maintenance-Window_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(45-SolarWinds-Maintenance-Window_tests PRIVATE include)
