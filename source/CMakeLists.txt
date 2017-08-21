include_directories("${GLFW_SOURCE_DIR}/deps")

add_library(StarForge STATIC
			../include/RenderDevice.hpp ../include/OpenGLRenderDevice.hpp
			../include/Platform.hpp ../include/Model.hpp
			../include/Mesh.hpp
			RenderDevice.cpp OpenGLRenderDevice.cpp
			GLFW_Platform.cpp 
			Model.cpp Mesh.cpp)

target_link_libraries(StarForge glfw glm)

target_include_directories(StarForge PUBLIC ../include)