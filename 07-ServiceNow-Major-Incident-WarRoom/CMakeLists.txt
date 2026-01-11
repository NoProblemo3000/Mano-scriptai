
cmake_minimum_required(VERSION 3.16)
project(07-ServiceNow-Major-Incident-WarRoom LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(07-ServiceNow-Major-Incident-WarRoom
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(07-ServiceNow-Major-Incident-WarRoom PRIVATE include)

# Tests (paprastas test runneris)
add_executable(07-ServiceNow-Major-Incident-WarRoom_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(07-ServiceNow-Major-Incident-WarRoom_tests PRIVATE include)
