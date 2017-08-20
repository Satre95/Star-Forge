include_directories("${GLFW_SOURCE_DIR}/deps")

add_library(StarForge STATIC RenderDevice.cpp OpenGLRenderDevice.cpp)

target_link_libraries(StarForge glfw glm)

target_include_directories(StarForge PUBLIC ../include)