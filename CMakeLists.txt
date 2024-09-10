CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

PROJECT(cheppers)

SET(CMAKE_CXX_STANDARD 23)

FILE(GLOB_RECURSE source_files CONFIGURE_DEPENDS "src/*")

add_library(cheppers_lib STATIC ${source_files})
TARGET_INCLUDE_DIRECTORIES(cheppers_lib PUBLIC "include/")

ADD_EXECUTABLE(cheppers main.cpp)
target_link_libraries(cheppers PRIVATE cheppers_lib)
