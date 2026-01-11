
cmake_minimum_required(VERSION 3.16)
project(40-SolarWinds-Perfstat-Collector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(40-SolarWinds-Perfstat-Collector
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(40-SolarWinds-Perfstat-Collector PRIVATE include)

# Tests (paprastas test runneris)
add_executable(40-SolarWinds-Perfstat-Collector_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(40-SolarWinds-Perfstat-Collector_tests PRIVATE include)
