#include <Platform.hpp>
#include <RenderDevice.hpp>
#include <glm/glm.hpp>

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
	Model * nanosuit = renderDevice->LoadModel("../../data/nanosuit/nanosuit.obj");
	renderDevice->InitAndAssignDefaultModelPipeline(*nanosuit);

	while (platform::PollPlatformWindow(window))
	{
		renderDevice->Clear(0.2f, 0.4f, 0.3f);
		glm::mat4 model, view, projection;
		platform::GetPlatformViewport(model, view, projection);
		renderDevice->DrawModel(*nanosuit, model, view, projection);

		platform::PresentPlatformWindow(window);
	}
	return 0;
}