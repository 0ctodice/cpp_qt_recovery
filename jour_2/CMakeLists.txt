cmake_minimum_required(VERSION 3.16)
project(HelloQt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Active les automations Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(exo1
    src/exo1.cpp
)

target_link_libraries(exo1 PRIVATE Qt6::Widgets)

add_executable(exo2
    src/exo2.cpp
)

target_link_libraries(exo2 PRIVATE Qt6::Widgets)

add_executable(main
    src/main.cpp
    src/folderBrowser.cpp
)

target_link_libraries(main PRIVATE Qt6::Widgets)
