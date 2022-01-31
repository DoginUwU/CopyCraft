# CMakeList.txt: projeto de CMake para CopyCraft, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

# Adicione a origem ao executável deste projeto.
add_executable (CopyCraft "CopyCraft.cpp" "CopyCraft.h" "window.h" "window.cpp" "input.h" "input.cpp" "engine.h" "engine.cpp")

target_include_directories(CopyCraft PRIVATE dependencies/glfw/include dependencies/glew/include)
target_link_directories(CopyCraft PRIVATE dependencies/glfw/lib-vc2022 dependencies/glew/lib/Release/x64)
target_link_libraries(CopyCraft PRIVATE glfw3.lib glew32.lib opengl32.lib)