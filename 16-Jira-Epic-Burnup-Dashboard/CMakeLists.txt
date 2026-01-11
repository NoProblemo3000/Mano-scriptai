
cmake_minimum_required(VERSION 3.16)
project(16-Jira-Epic-Burnup-Dashboard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(16-Jira-Epic-Burnup-Dashboard
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(16-Jira-Epic-Burnup-Dashboard PRIVATE include)

# Tests (paprastas test runneris)
add_executable(16-Jira-Epic-Burnup-Dashboard_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(16-Jira-Epic-Burnup-Dashboard_tests PRIVATE include)
