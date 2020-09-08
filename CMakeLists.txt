cmake_minimum_required(VERSION 3.14)
project(die)
add_executable(die
    main.cpp die_faces.cpp GLUtils.cpp Shader.c
)

target_include_directories(die PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../vcpkg/installed/x64-windows/include
    ${CMAKE_CURRENT_LIST_DIR}/../vcpkg/installed/x64-windows/include/opencv4
)

target_link_directories(die PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../vcpkg/installed/x64-windows/debug/lib
)

target_link_libraries(die
    glew32d.lib glfw3dll.lib opengl32.lib opencv_cored.lib opencv_imgprocd.lib opencv_imgcodecsd.lib
)