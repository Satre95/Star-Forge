#include "DefaultShaders.hpp"
namespace starforge
{
	const char * g_defaultVertexShaderSource = R"END(
#version 450 core
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;
layout (location = 5) in vec4 aColor;

out vec3 FragNormal;
out vec2 FragTexCoord;
out vec3 FragTangent;
out vec3 FragBitangent;
out vec4 FragVertColor;

void main()
{
	gl_Position = uProjection * uView * uModel * vec4(aPos, 1.0f);
	FragNormal = aNormal;
	FragTexCood = aTexCoord;
	FragTangent = aTangent;
	FragBitangent = aBitangent;
	FragVertColor = aColor;
}
	)END";

	const char * g_defaultPixelShaderSource = R"END(
#version 450 core
// Allows shader to detect if textures are bound (requires OpenGL >= 4.2)
// see: https://www.khronos.org/registry/OpenGL/extensions/ARB/ARB_texture_query_levels.txt
#extension GL_ARB_texture_query_levels

uniform sampler2D uTextureDiffuse;
uniform sampler2D uTextureSpecular;
uniform sampler2D uTextureNormal;
uniform sampler2D uTextureHeight;

in vec3 FragNormal;
in vec2 FragTexCoord;
in vec3 FragTangent;
in vec3 FragBitangent;
in vec4 FragVertColor;

out vec4 FragColor;

void main()
{
	//TODO: Check diffuse texture
	if(textureQueryLevels(uTextureDiffuse) != 0)
		FragColor = texture(uTextureDiffuse, FragTexCoord);
	//TODO: Check specular texture
	//TODO: Check for vertex color
	//TODO: Perform lighting calculations

	//FragColor = vec4(texture(uTextureSampler, FragTexCoord).rgb, 1);
}
	)END";
}