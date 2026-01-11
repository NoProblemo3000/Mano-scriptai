
cmake_minimum_required(VERSION 3.16)
project(03-ServiceNow-CMDB-Importer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(03-ServiceNow-CMDB-Importer
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(03-ServiceNow-CMDB-Importer PRIVATE include)

# Tests (paprastas test runneris)
add_executable(03-ServiceNow-CMDB-Importer_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(03-ServiceNow-CMDB-Importer_tests PRIVATE include)
