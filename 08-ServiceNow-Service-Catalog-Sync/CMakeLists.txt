
cmake_minimum_required(VERSION 3.16)
project(08-ServiceNow-Service-Catalog-Sync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(08-ServiceNow-Service-Catalog-Sync
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(08-ServiceNow-Service-Catalog-Sync PRIVATE include)

# Tests (paprastas test runneris)
add_executable(08-ServiceNow-Service-Catalog-Sync_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(08-ServiceNow-Service-Catalog-Sync_tests PRIVATE include)
