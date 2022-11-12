#pragma once
#include <Texture.h>

#define WRAP_X GL_TEXTURE_WRAP_S
#define WRAP_Y GL_TEXTURE_WRAP_T

#define CLAMP_X GL_TEXTURE_CLAMP_S
#define CLAMP_Y GL_TEXTURE_CLAMP_T

#define LINEAR_MIP_LINEAR GL_LINEAR_MIPMAP_LINEAR
#define POINT_MIP_LINEAR GL_NEAREST_MIPMAP_LINEAR
#define LINEAR_MIP_POINT GL_LINEAR_MIPMAP_NEAREST
#define POINT_MIP_POINT GL_NEAREST_MIPMAP_LINEAR

class Sampler
{
public:
	Sampler(Texture& texture,
		int wrap_mode_x = WRAP_X, int wrap_mode_y = WRAP_Y,
		int filtering = LINEAR_MIP_LINEAR);
	void Bind();

private:
	Texture& m_texture;
	int m_wrap_mode_x;
	int m_wrap_mode_y;
	int m_filtering;
};

