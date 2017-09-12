#include <Platform.hpp>
#include <RenderDevice.hpp>


#ifdef __APPLE__
const char *vertexShaderSource = "#version 410 core\n"
#else
const char *vertexShaderSource = "#version 450 core\n"
#endif
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";


#ifdef __APPLE__
const char *pixelShaderSource = "#version 410 core\n"
#else
const char *pixelShaderSource = "#version 450 core\n"
#endif
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

int main()
{
	platform::InitPlatform();

	// window creation
	// --------------------
	platform::PLATFORM_WINDOW_REF window =
		platform::CreatePlatformWindow(800, 600, "Triangle");
	if (!window)
	{
		platform::TerminatePlatform();
		return -1;
	}

	starforge::RenderDevice *renderDevice = starforge::CreateRenderDevice();

	// build and compile our shader program
	// ------------------------------------
	// vertex shader
	starforge::VertexShader *vertexShader = renderDevice->CreateVertexShader(vertexShaderSource);

	// fragment shader
	starforge::PixelShader *pixelShader = renderDevice->CreatePixelShader(pixelShaderSource);

	// link shaders
	starforge::Pipeline *pipeline = renderDevice->CreatePipeline(vertexShader, pixelShader);

	renderDevice->DestroyVertexShader(vertexShader);
	renderDevice->DestroyPixelShader(pixelShader);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left
		 0.5f, -0.5f, 0.0f, // right
		 0.0f,  0.5f, 0.0f  // top
	};

	starforge::VertexBuffer *vertexBuffer = renderDevice->CreateVertexBuffer(sizeof(vertices), vertices);

	starforge::VertexElement vertexElement = { 0, starforge::VERTEXELEMENTTYPE_FLOAT, 3, 0, 0, };
	starforge::VertexDescription *vertexDescription = renderDevice->CreateVertexDescription(1, &vertexElement);

	starforge::VertexArray *vertexArray = renderDevice->CreateVertexArray(1, &vertexBuffer, &vertexDescription);

	// render loop
	// -----------
	while (platform::PollPlatformWindow(window))
	{
		// render
		// ------
		renderDevice->Clear(0.2f, 0.3f, 0.3f, 1.0f, 1.0f);

		// draw our first triangle
		renderDevice->SetPipeline(pipeline);
		renderDevice->SetVertexArray(vertexArray);
		renderDevice->DrawTriangles(0, 3);

		platform::PresentPlatformWindow(window);
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	renderDevice->DestroyVertexArray(vertexArray);
	renderDevice->DestroyVertexDescription(vertexDescription);
	renderDevice->DestroyVertexBuffer(vertexBuffer);
	renderDevice->DestroyPipeline(pipeline);

	platform::TerminatePlatform();

	return 0;
}
