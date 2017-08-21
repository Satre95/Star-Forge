#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "RenderDevice.hpp"

namespace starforge
{
	class Mesh
	{
	public:
		Mesh(std::vector <float> &, std::vector<unsigned int> &, const VertexDescription &, RenderDevice &);
		~Mesh();

		///Draws the mesh. Expects the pipeline view and projection matrices to already be set.
		void Draw(RenderDevice &, const glm::mat4 & toWorld);
		void SetPipeline(Pipeline * pipeIn) { m_pipeline = pipeIn; }
		void SetModelMatrix(const glm::mat4 & mat) { m_modelMatrix = mat; }
	protected:
		Mesh(); //Direct creation is disallowed.

	private:
		/**
		 * The vertices of this mesh are stored as a generic array of floats,
		 * the element description is used at runtime to specify the attributes.
		 */
		std::vector <float> m_vertices;
		/// Indices of this mesh.
		std::vector <unsigned int> m_indices;
		/// The textures used by this mesh
		std::vector <Texture2D *> m_textures;
		/// Describes the information on each vertex
		VertexDescription * m_vertexDescription;
		/// Encapsulation of the VBO in GPU mem.
		VertexBuffer *m_vbo = nullptr;
		/// Encapsulation of the VAO in GPU mem
		VertexArray *m_vao = nullptr;
		/// Encapsulation of the EBO in GPU mem
		IndexBuffer *m_ebo = nullptr;
		/**
		 * The shader and draw pipeline that this mesh uses to draw itself.
		 *
		 * NOTE: The pipline is considered owned by the parent Model of this mesh, not
		 * the mesh itself, hence the mesh does not destroy the pipeline when it is destroyed.
		 */
		Pipeline *m_pipeline = nullptr;
		/// The model matrix of this mesh.
		glm::mat4 m_modelMatrix;
		/// Allocates the buffers and GPU mem.
		void InitBuffers(RenderDevice & renderdevice);
	};
}