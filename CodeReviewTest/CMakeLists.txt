cmake_minimum_required(VERSION 2.8.12)

project(CodeReviewTest)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

set(PROJECT_HADERS
    Faktory.h
)
set(PROJECT_SOURCE
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${PROJECT_HADERS}
    ${PROJECT_SOURCE}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
