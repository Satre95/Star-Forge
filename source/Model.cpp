#include "Model.hpp"

namespace starforge
{
	Model::Model(const std::string & path, bool gamma) : m_gammaCorrection(gamma)
	{
	}

	void Model::Load(const std::string & path)
	{
	}

	void Model::InitPipeline(RenderDevice & renderDevice, Pipeline * pipeline)
	{
	}

	void Model::Draw(RenderDevice & renderDevice)
	{
		//TODO: Add call to logger after logger is implemented.
		if (m_pipeline == nullptr) return;

		//Set the shader uniforms.
		m_pipeline->GetParam("uModel")->SetAsMat4(glm::value_ptr(m_modelMatrix));
	}
}