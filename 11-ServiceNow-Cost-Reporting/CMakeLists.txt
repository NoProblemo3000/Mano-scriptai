
cmake_minimum_required(VERSION 3.16)
project(11-ServiceNow-Cost-Reporting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(11-ServiceNow-Cost-Reporting
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(11-ServiceNow-Cost-Reporting PRIVATE include)

# Tests (paprastas test runneris)
add_executable(11-ServiceNow-Cost-Reporting_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(11-ServiceNow-Cost-Reporting_tests PRIVATE include)
