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
		//NOTE: Do not use this constructor directly, instead use RenderDevice::LoadModel
		Model(std::string const & path, RenderDevice & renderDevice, bool gamma = false);
		void Load(std::string path, RenderDevice & renderDevice);
		//void Draw(RenderDevice & renderDevice);

		void SetPipeline(Pipeline * pipeline) { m_pipeline = pipeline; }
		Pipeline * GetPipeline() const { return m_pipeline; }
		Mesh * GetMesh(size_t i) const { return m_meshes.at(i); }
		size_t NumMeshes() const { return m_meshes.size(); }
		void AddMesh(Mesh * mesh) { m_meshes.push_back(mesh); }
		
	protected:
		Model() {};

	private:
		void ProcessNode(aiNode * node, const aiScene * scene, RenderDevice & renderDevice);
		Mesh * ProcessMesh(aiMesh * mesh, const aiScene * scene, RenderDevice & renderDevice);
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