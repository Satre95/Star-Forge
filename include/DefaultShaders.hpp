#pragma once

namespace starforge {
	/**
	 * The default vertex shader.
	 *
	 * Supports vertices with attributes with bindgin locations in the following order:
	 *  0. position
	 *  1. texture coordinate
	 *  2. tangent
	 *  3. bitangent
	 *  4. color
	 */
	const char * g_defaultVertexShader = R"END(
#version 450 core
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aTangent;
layout (location = 3) in vec3 aBitangent;
layout (location = 4) in vec4 aColor;

out vec2 FragTexCoord;
out vec3 FragTangent;
out vec3 FragBitangent;
out vec4 FragColor;

void main()
{
	gl_Position = uProjection * uView * uModel * vec4(aPos, 1.0f);
	FragTexCood = aTexCoord;
	FragTangent = aTangent;
	FragBitangent = aBitangent;
	FragColor = aColor;
}
	)END";

	/**
	 * The default fragment shader.
	 *
	 * Supports up to 4 textures:
	 *  - uTextureDiffuse
	 *  - uTextureSpecular
	 *  - uTextureNormal
	 *  - uTextureHeight
	 *
	 * First, diffuse & specular textures are checked. If not provided, then
	 * vertex color is checked. If that is also not provided, then a default
	 * color of blue-green is used.
	*/
	const char * g_defaultFragmentShader = R"END(
#version 450 core
// Allows shader to detect if textures are bound (requires OpenGL >= 4.2)
// see: https://www.khronos.org/registry/OpenGL/extensions/ARB/ARB_texture_query_levels.txt
#extension GL_ARB_texture_query_levels

uniform sampler2D uTextureDiffuse;
uniform sampler2D uTextureSpecular;
uniform sampler2D uTextureNormal;
uniform sampler2D uTextureHeight;

in vec2 FragTexCoord;
in vec3 FragTangent;
in vec3 FragBitangent;
in vec4 FragColor;

out vec4 FragColor;

void main()
{
	//TODO: Check diffuse texture
	//TODO: Check specular texture
	//TODO: Check for vertex color
	//TODO: Perform lighting calculations

	FragColor = vec4(texture(uTextureSampler, FragTexCoord).rgb, 1);
}
	)END";
}