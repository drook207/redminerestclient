cmake_minimum_required(VERSION 3.16)

project(redminerestclient LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Network LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network
  LinguistTools)

qt_standard_project_setup()
set(TS_FILES redminerestclient_en_US.ts)

add_library(redminerestclient SHARED
  src/redminerestclient_global.h
  src/restclient.cpp
  src/restclient.hpp
)
target_link_libraries(redminerestclient PRIVATE Qt${QT_VERSION_MAJOR}::Core
                      Qt${QT_VERSION_MAJOR}::Network expected)

target_compile_definitions(redminerestclient PRIVATE REDMINERESTCLIENT_LIBRARY)

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/src/translations ${TS_FILES})

