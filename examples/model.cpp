#include <Platform.hpp>
#include <RenderDevice.hpp>
#include <glm/glm.hpp>
#include "Model.hpp"

int main() {
	using namespace starforge;
	platform::InitPlatform();

	platform::PLATFORM_WINDOW_REF window =
		platform::CreatePlatformWindow(800, 800, "Model");
	if (!window)
	{
		platform::TerminatePlatform();
		return -1;
	}

	RenderDevice * renderDevice = starforge::CreateRenderDevice();
	Model * nanosuit = new Model("../data/nanosuit/nanosuit.obj", *renderDevice);

    VertexShader *vertexShader = renderDevice->CreateVertexShader(g_defaultVertexShaderSource);
    PixelShader *pixelShader = renderDevice->CreatePixelShader(g_defaultPixelShaderSource);
    Pipeline *pipeline = renderDevice->CreatePipeline(vertexShader, pixelShader);

    //Set the texture uniforms
    if (pipeline->GetParam("uTextureDiffuse"))
        pipeline->GetParam("uTextureDiffuse")->SetAsInt(0);
    if (pipeline->GetParam("uTextureSpecular"))
        pipeline->GetParam("uTextureSpecular")->SetAsInt(1);
    if (pipeline->GetParam("uTextureNormal"))
        pipeline->GetParam("uTextureNormal")->SetAsInt(2);
    if (pipeline->GetParam("uTextureHeight"))
        pipeline->GetParam("uTextureHeight")->SetAsInt(3);

    renderDevice->DestroyVertexShader(vertexShader);
    renderDevice->DestroyPixelShader(pixelShader);

    nanosuit->SetPipeline(pipeline);

	while (platform::PollPlatformWindow(window))
	{
		renderDevice->Clear(0.2f, 0.4f, 0.3f);
		glm::mat4 arcball, view, projection;
		platform::GetPlatformViewport(arcball, view, projection);
		renderDevice->DrawModel(*nanosuit, arcball, view, projection);

		platform::PresentPlatformWindow(window);
	}
	return 0;
}
