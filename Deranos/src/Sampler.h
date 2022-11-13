#pragma once
#include <Texture.h>

#define WRAP GL_REPEAT 
#define CLAMP GL_CLAMP_TO_EDGE
#define MIRROR GL_MIRRORED_REPEAT

#define LINEAR_MIP_LINEAR GL_LINEAR_MIPMAP_LINEAR
#define POINT_MIP_LINEAR GL_NEAREST_MIPMAP_LINEAR
#define LINEAR_MIP_POINT GL_LINEAR_MIPMAP_NEAREST
#define POINT_MIP_POINT GL_NEAREST_MIPMAP_LINEAR

class Sampler
{
public:
	Sampler(Texture& texture, int texture_slot, int wrap_mode = WRAP, int filtering = LINEAR_MIP_LINEAR);
	void Bind();

private:
	Texture& m_texture;
	int m_texture_slot;
	int m_wrap_mode;
	int m_filtering;
};

