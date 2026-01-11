
cmake_minimum_required(VERSION 3.16)
project(09-ServiceNow-User-Provisioning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(09-ServiceNow-User-Provisioning
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(09-ServiceNow-User-Provisioning PRIVATE include)

# Tests (paprastas test runneris)
add_executable(09-ServiceNow-User-Provisioning_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(09-ServiceNow-User-Provisioning_tests PRIVATE include)
