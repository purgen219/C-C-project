cmake_minimum_required(VERSION 3.12)
project(Test_Game)

set(CMAKE_CXX_STANDARD 14)
add_executable(Test_Game main.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Test_Game ${SFML_LIBRARIES})
endif()