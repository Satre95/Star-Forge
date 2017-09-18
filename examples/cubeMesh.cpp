#include <Platform.hpp>

#include <RenderDevice.hpp>
#include <Cube.hpp>
#include <cstdint>

#ifdef __APPLE__
const char *vertexShaderSource = "#version 410 core\n"
#else
const char *vertexShaderSource = "#version 450 core\n"
#endif
"uniform mat4 uModel;\n"
"uniform mat4 uView;\n"
"uniform mat4 uProjection;\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aNormal;\n"
"layout (location = 2) in vec2 aTexCoord;\n"
"void main()\n"
"{\n"
"   gl_Position = uProjection * uView * uModel * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}";
#ifdef __APPLE__
const char *pixelShaderSource = "#version 410 core\n"
#else
const char *pixelShaderSource = "#version 450 core\n"
#endif
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f);\n"
"}\n";

using namespace starforge;
int main() {
	platform::InitPlatform();

	platform::PLATFORM_WINDOW_REF window =
		platform::CreatePlatformWindow(800, 800, "Cube Mesh Example");
	if (!window)
	{
		platform::TerminatePlatform();
		return -1;
	}

	starforge::RenderDevice *renderDevice = starforge::CreateRenderDevice();

	starforge::VertexShader *vertexShader = renderDevice->CreateVertexShader(vertexShaderSource);

	starforge::PixelShader *pixelShader = renderDevice->CreatePixelShader(pixelShaderSource);

	starforge::Pipeline *pipeline = renderDevice->CreatePipeline(vertexShader, pixelShader);

	// Get shader parameter for model matrix; we will set it every frame
	starforge::PipelineParam *uModelParam =
		pipeline->GetParam("uModel");

	// Get shader parameter for view matrix; we will set it every frame
	starforge::PipelineParam *uViewParam =
		pipeline->GetParam("uView");

	// Get shader parameter for projection matrix; we will set it every frame
	starforge::PipelineParam *uProjectionParam =
		pipeline->GetParam("uProjection");

	renderDevice->DestroyVertexShader(vertexShader);
	renderDevice->DestroyPixelShader(pixelShader);

	Cube * cubeMesh = new Cube(*renderDevice, 1.0f);

	while (platform::PollPlatformWindow(window)) {
		glm::mat4 model, view, projection;
		platform::GetPlatformViewport(model, view, projection);

		uModelParam->SetAsMat4(glm::value_ptr(model));
		uViewParam->SetAsMat4(glm::value_ptr(view));
		uProjectionParam->SetAsMat4(glm::value_ptr(projection));

		renderDevice->Clear(0.2f, 0.3f, 0.3f);

		renderDevice->DrawMesh(*cubeMesh, *pipeline);

		platform::PresentPlatformWindow(window);

	}

	delete cubeMesh;
	return 0;
}