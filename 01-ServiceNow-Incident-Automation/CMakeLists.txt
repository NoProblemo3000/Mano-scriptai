
cmake_minimum_required(VERSION 3.16)
project(01-ServiceNow-Incident-Automation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01-ServiceNow-Incident-Automation
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(01-ServiceNow-Incident-Automation PRIVATE include)

# Tests (paprastas test runneris)
add_executable(01-ServiceNow-Incident-Automation_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(01-ServiceNow-Incident-Automation_tests PRIVATE include)
