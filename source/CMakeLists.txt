include_directories("${GLFW_SOURCE_DIR}/deps" "../externals/assimp/include")

add_library(StarForge STATIC
		../include/RenderDevice.hpp ../include/OpenGLRenderDevice.hpp
		../include/Platform.hpp ../include/Model.hpp
		../include/Mesh.hpp ../include/DefaultShaders.hpp
            ../include/Node.hpp ../include/GroupNode.hpp
            ../include/MatrixTransformNode.hpp ../include/Geode.hpp
            ../include/SceneGraph.hpp 
            ../include/Cube.hpp

		RenderDevice.cpp OpenGLRenderDevice.cpp
		GLFW_Platform.cpp 
		Model.cpp Mesh.cpp
            Cube.cpp
            DefaultShaders.cpp Node.cpp
            GroupNode.cpp MatrixTransformNode.cpp
            Geode.cpp
            SceneGraph.cpp)

target_link_libraries(StarForge glfw glm assimp)

target_include_directories(StarForge PUBLIC ../include)
