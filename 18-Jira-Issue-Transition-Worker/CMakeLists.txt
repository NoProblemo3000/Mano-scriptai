
cmake_minimum_required(VERSION 3.16)
project(18-Jira-Issue-Transition-Worker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(18-Jira-Issue-Transition-Worker
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(18-Jira-Issue-Transition-Worker PRIVATE include)

# Tests (paprastas test runneris)
add_executable(18-Jira-Issue-Transition-Worker_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(18-Jira-Issue-Transition-Worker_tests PRIVATE include)
