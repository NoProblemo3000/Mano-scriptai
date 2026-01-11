
cmake_minimum_required(VERSION 3.16)
project(42-SolarWinds-Custom-Poller-Manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(42-SolarWinds-Custom-Poller-Manager
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(42-SolarWinds-Custom-Poller-Manager PRIVATE include)

# Tests (paprastas test runneris)
add_executable(42-SolarWinds-Custom-Poller-Manager_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(42-SolarWinds-Custom-Poller-Manager_tests PRIVATE include)
