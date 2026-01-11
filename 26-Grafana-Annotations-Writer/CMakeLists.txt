
cmake_minimum_required(VERSION 3.16)
project(26-Grafana-Annotations-Writer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(26-Grafana-Annotations-Writer
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(26-Grafana-Annotations-Writer PRIVATE include)

# Tests (paprastas test runneris)
add_executable(26-Grafana-Annotations-Writer_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(26-Grafana-Annotations-Writer_tests PRIVATE include)
