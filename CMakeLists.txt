cmake_minimum_required(VERSION 3.10)
project(NozdorLauncher)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(NozdorLauncher
    main.cpp
    launcher.cpp
    launcher.h
)

target_link_libraries(NozdorLauncher PRIVATE Qt6::Widgets)
