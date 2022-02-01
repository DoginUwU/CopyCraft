# CMakeList.txt: projeto de CMake para CopyCraft, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

# Adicione a origem ao executável deste projeto.
add_executable (CopyCraft "CopyCraft.cpp" "CopyCraft.h" "window.h" "window.cpp" "input.h" "input.cpp" "engine.h" "engine.cpp" "shader.h" "shader.cpp" "file.h" "file.cpp" "shader-program.h" "shader-program.cpp" "stb_image.h" "texture.h" "image.h" "image.cpp" "texture.cpp" "object.h" "object.cpp" "mesh.h" "mesh.cpp" "transform.h" "transform.cpp" "camera.h" "camera.cpp" "fly-camera.h" "fly-camera.cpp" "delta-time.h" "delta-time.cpp" "game-controller.h" "game-controller.cpp" "game-object.h" "game-object.cpp")

target_include_directories(CopyCraft PRIVATE dependencies/glm dependencies/glfw/include dependencies/glew/include)
target_link_directories(CopyCraft PRIVATE dependencies/glfw/lib-vc2022 dependencies/glew/lib/Release/x64)
target_link_libraries(CopyCraft PRIVATE glfw3.lib glew32.lib opengl32.lib)

add_custom_command(TARGET CopyCraft POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}/CopyCraft/glew32.dll"
				   COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/shaders" "${CMAKE_BINARY_DIR}/CopyCraft/shaders"
				   COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/textures" "${CMAKE_BINARY_DIR}/CopyCraft/textures"
)