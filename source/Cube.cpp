#include "Cube.hpp"
namespace starforge {
	//CCW winding is front.
	Cube::CubeVertex Cube::unitCubeVerts[36] = {
		// Front face
		CubeVertex(-0.5f, -0.5f, 0.5f, 0.f, 0.f, 1.f, 0.f, 0.f),	//Left, Bottom, Front
		CubeVertex(0.5f, -0.5f, 0.5f, 0.f, 0.f, 1.f, 0.f, 1.f),		//Right, Bottom, Front
		CubeVertex(0.5f, 0.5f, 0.5f, 0.f, 0.f, 1.f, 1.f, 1.f),		//Right, Top, Front

		CubeVertex(0.5f, 0.5f, 0.5f, 0.f, 0.f, 1.f, 1.f, 1.f),		//Right, Top, Front
		CubeVertex(-0.5f, 0.5f, 0.5f, 0.f, 0.f, 1.f, 1.f, 0.f),		//Left, Top, Front
		CubeVertex(-0.5f, -0.5f, 0.5f, 0.f, 0.f, 1.f, 0.f, 0.f),	//Left, Bottom, Front


		// Back face
		CubeVertex(-0.5f, -0.5f, -0.5f, 0.f, 0.f, -1.f, 1.f, 0.f),	//Left, Bottom, Back
		CubeVertex(-0.5f, 0.5f, -0.5f, 0.f, 0.f, -1.f, 1.f, 1.f),	//Left, Top, Back
		CubeVertex(0.5f, 0.5f, -0.5f, 0.f, 0.f, -1.f, 0.f, 1.f),	//Right, Top, Back

		CubeVertex(0.5f, 0.5f, -0.5f, 0.f, 0.f, -1.f, 0.f, 1.f),	//Right, Top, Back
		CubeVertex(0.5f, -0.5f, -0.5f, 0.f, 0.f, -1.f, 0.f, 0.f),	//Right, Bottom, Back
		CubeVertex(-0.5f, -0.5f, -0.5f, 0.f, 0.f, -1.f, 1.f, 0.f),	//Left, Bottom, Back


		// Top Face
		CubeVertex(-0.5f, 0.5f, -0.5f, 0.f, 1.f, 0.f, 0.f, 1.f),	//Left, Top, Back
		CubeVertex(-0.5f, 0.5f, 0.5f, 0.f, 1.f, 0.f, 0.f, 0.f),		//Left, Top, Front
		CubeVertex(0.5f, 0.5f, 0.5f, 0.f, 1.f, 0.f, 1.f, 0.f),		//Right, Top, Front

		CubeVertex(0.5f, 0.5f, 0.5f, 0.f, 1.f, 0.f, 1.f, 0.f),		//Right, Top, Front
		CubeVertex(0.5f, 0.5f, -0.5f, 0.f, 1.f, 0.f, 1.f, 1.f),		//Right, Top, Back
		CubeVertex(-0.5f, 0.5f, -0.5f, 0.f, 1.f, 0.f, 0.f, 1.f),	//Left, Top, Back


		// Bottom Face
		CubeVertex(-0.5f, -0.5f, 0.5f, 0.f, -1.f, 0.f, 0.f, 1.f),	//Left, Bottom, Front
		CubeVertex(-0.5f, -0.5f, -0.5f, 0.f, -1.f, 0.f, 0.f, 0.f),	//Left, Bottom, Back
		CubeVertex(0.5f, -0.5f, -0.5f, 0.f, -1.f, 0.f, 1.f, 0.f),	//Right, Bottom, Back

		CubeVertex(0.5f, -0.5f, -0.5f, 0.f, -1.f, 0.f, 1.f, 0.f),	//Right, Bottom, Back
		CubeVertex(0.5f, -0.5f, 0.5f, 0.f, 0.f, 1.f, 1.f, 1.f),		//Right, Bottom, Front
		CubeVertex(-0.5f, -0.5f, 0.5f, 0.f, -1.f, 0.f, 0.f, 1.f),	//Left, Bottom, Front

		// Right face
		CubeVertex(0.5f, 0.5f, 0.5f, 1.f, 0.f, 0.f, 0.f, 1.f),		//Right, Top, Front
		CubeVertex(0.5f, -0.5f, 0.5f, 1.f, 0.f, 0.f, 0.f, 0.f),		//Right, Bottom, Front
		CubeVertex(0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f, 1.f, 0.f),	//Right, Bottom, Back

		CubeVertex(0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f, 1.f, 0.f),	//Right, Bottom, Back
		CubeVertex(0.5f, 0.5f, -0.5f, 1.f, 0.f, 0.f, 1.f, 1.f),		//Right, Top, Back
		CubeVertex(0.5f, 0.5f, 0.5f, 1.f, 0.f, 0.f, 0.f, 1.f),		//Right, Top, Front


		// Left Face
		CubeVertex(-0.5f, 0.5f, 0.5f, -1.f, 0.f, 0.f, 1.f, 1.f),	//Left, Top, Front
		CubeVertex(-0.5f, 0.5f, -0.5f, -1.f, 0.f, 0.f, 0.f, 1.f),	//Left, Top, Back
		CubeVertex(-0.5f, -0.5f, -0.5f, -1.f, 0.f, 0.f, 0.f, 0.f),	//Left, Bottom, Back

		CubeVertex(-0.5f, -0.5f, -0.5f, -1.f, 0.f, 0.f, 0.f, 0.f),	//Left, Bottom, Back
		CubeVertex(-0.5f, -0.5f, 0.5f, -1.f, 0.f, 0.f, 1.f, 0.f),	//Left, Bottom, Front
		CubeVertex(-0.5f, 0.5f, 0.5f, -1.f, 0.f, 0.f, 1.f, 1.f)	//Left, Top, Front
	};

	Cube::Cube(float size) {
		size_t numFloats = CubeVertex::NumComponents() * 36;
		m_vertices.reserve(numFloats);
		for(size_t i = 0; i < 36; i++) {
			CubeVertex & aVertex = unitCubeVerts[i];
			m_vertices.push_back(aVertex.x * size);
			m_vertices.push_back(aVertex.y * size);
			m_vertices.push_back(aVertex.z * size);
			m_vertices.push_back(aVertex.nx);
			m_vertices.push_back(aVertex.ny);
			m_vertices.push_back(aVertex.nz);
			m_vertices.push_back(aVertex.u);
			m_vertices.push_back(aVertex.v);
		}

	}

	Cube::~Cube() {

	}
}