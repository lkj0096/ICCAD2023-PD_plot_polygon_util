cmake_minimum_required(VERSION 3.18)
project(fltk_plot_polygon)
set(my_app_name fltk_plot_polygon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3")
set(fltk_prefix ${CMAKE_SOURCE_DIR}/fltk-1.4-build)
set(fltk_INCLUDE_DIR ${fltk_prefix}/include/)

include_directories(${fltk_INCLUDE_DIR})

FILE(GLOB_RECURSE all_source_files "src/*.cpp" "src/*.c")
FILE(GLOB_RECURSE all_header_files "src/*.hpp" "src/*.h")


IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    
    MESSAGE(STATUS "current platform: Windows")
    LINK_DIRECTORIES("${fltk_prefix}/lib/Windows-release")
    ADD_EXECUTABLE( ${my_app_name}
            WIN32
            main.cpp
			${all_header_files}
            ${all_source_files}
    )
    TARGET_LINK_LIBRARIES(
            ${my_app_name}
            PRIVATE
            fltk
            gdiplus
            ws2_32
            comctl32
    )
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: macOS")
    LINK_DIRECTORIES("${fltk_prefix}/lib/macOS-release")
    ADD_EXECUTABLE(
            ${my_app_name}
            ${all_header_files}
            ${all_source_files}
    )
    TARGET_LINK_LIBRARIES(
            ${my_app_name}
            PRIVATE
            fltk
            "-framework Cocoa"
    )
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")

    LINK_DIRECTORIES("${fltk_prefix}/lib/Linux-release")
    ADD_EXECUTABLE(
            ${my_app_name}
            ${all_header_files}
            ${all_source_files}
    )
    TARGET_LINK_LIBRARIES(
            ${my_app_name}
            PRIVATE
            fltk
            X11
            dl
    )
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF ()