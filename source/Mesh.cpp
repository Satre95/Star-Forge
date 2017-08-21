#include "Mesh.hpp"
#include "Platform.hpp"

namespace starforge
{
	Mesh::Mesh() {}

	Mesh::Mesh(std::vector <float>& vertsIn,
		std::vector<unsigned int>& indicesIn,
		const VertexDescription & vdIn,
		RenderDevice & renderDevice) : m_vertexDescription(new VertexDescription(vdIn))
	{
		m_vertices = vertsIn;
		m_indices = indicesIn;
		InitBuffers(renderDevice);
	}

	Mesh::~Mesh()
	{
		delete m_ebo; delete m_vbo;
		delete m_vao; delete m_vertexDescription;
	}

	void Mesh::InitBuffers(RenderDevice & renderDevice)
	{
		m_vbo = renderDevice.CreateVertexBuffer(m_vertices.size(), m_vertices.data());
		m_ebo = renderDevice.CreateIndexBuffer(m_indices.size(), m_indices.data());

		m_vao = renderDevice.CreateVertexArray(1, &m_vbo, &m_vertexDescription);
	}

	void Mesh::Draw(RenderDevice & renderDevice, const glm::mat4 & toWorld)
	{
		//TODO: Add call to logger after logger is implemented.
		if (m_pipeline == nullptr) return;

		m_pipeline->GetParam("uModel")->SetAsMat4(glm::value_ptr(toWorld * m_modelMatrix));

		// set the texture slots
		for (size_t i = 0; i < m_textures.size(); i++)
			renderDevice.SetTexture2D(i, m_textures.at(i));

		renderDevice.SetPipeline(m_pipeline);
		renderDevice.SetVertexArray(m_vao);
		renderDevice.SetIndexBuffer(m_ebo);

		renderDevice.DrawTrianglesIndexed32(0, m_indices.size());
	}
}