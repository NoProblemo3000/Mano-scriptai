
cmake_minimum_required(VERSION 3.16)
project(27-Grafana-Alert-Rules-Sync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(27-Grafana-Alert-Rules-Sync
    src/main.cpp
    src/oauth_stub.cpp
    src/http_client_stub.cpp
)

target_include_directories(27-Grafana-Alert-Rules-Sync PRIVATE include)

# Tests (paprastas test runneris)
add_executable(27-Grafana-Alert-Rules-Sync_tests tests/test_main.cpp src/oauth_stub.cpp src/http_client_stub.cpp)
target_include_directories(27-Grafana-Alert-Rules-Sync_tests PRIVATE include)
