#pragma once

#include <vector>
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "RenderDevice.hpp"
#include "Mesh.hpp"
#include "DefaultShaders.hpp"

namespace starforge {
	class Model {
	public:
		Model(std::string const & path, bool gamma = false);
		void Draw(RenderDevice & renderDevice);
		void Load(std::string const & path, RenderDevice &);
		/// Initializes the shader pipeline. If null or no argument is given,
		/// class will automoatically generate a default pipeline.
		void InitPipeline(RenderDevice & device, Pipeline * pipeline = nullptr);
	protected:
		Model() {};

	private:
		void Load(std::string path, RenderDevice &);
		void ProcessNode(aiNode * node, const aiScene * scene, RenderDevice &);
		Mesh * ProcessMesh(aiMesh * mesh, const aiScene * scene, RenderDevice &);
		/**
		 * The shader and draw pipeline that this mesh uses to draw itself.
		 *
		 * NOTE: The pipline is considered owned by the parent Model of this mesh, not
		 * the mesh itself, hence the mesh does not destroy the pipeline when it is destroyed.
		 */
		Pipeline *m_pipeline = nullptr;
		/// The model matrix of this mesh.
		glm::mat4 m_modelMatrix;
		bool m_gammaCorrection;
		std::vector<Mesh *> m_meshes;
		std::vector<Texture2D *> m_texturesLoaded;
	};
}