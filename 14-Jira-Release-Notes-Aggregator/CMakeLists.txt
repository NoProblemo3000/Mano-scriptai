
cmake_minimum_required(VERSION 3.16)
project(14-Jira-Release-Notes-Aggregator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(14-Jira-Release-Notes-Aggregator
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(14-Jira-Release-Notes-Aggregator PRIVATE include)

# Tests (paprastas test runneris)
add_executable(14-Jira-Release-Notes-Aggregator_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(14-Jira-Release-Notes-Aggregator_tests PRIVATE include)
