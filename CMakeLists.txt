cmake_minimum_required(VERSION 3.5.0)
project(Lab02 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Lab02 src/main.cpp)
add_library(BigInt src/BigInt.cpp)

target_link_libraries(Lab02 BigInt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
