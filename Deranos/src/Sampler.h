#pragma once
#include <Texture.h>

enum class EWrapMode {
	Default = GL_CLAMP_TO_EDGE,
	Wrap = GL_REPEAT,
	Clamp = GL_CLAMP_TO_EDGE,
	Mirror = GL_MIRRORED_REPEAT
};


enum class EFilteringMode { 
	Default = GL_NEAREST,
	Point = GL_NEAREST,
	Linear = GL_LINEAR,
	LinearMipLinear = GL_LINEAR_MIPMAP_LINEAR, 
	PointMipLinear = GL_NEAREST_MIPMAP_LINEAR, 
	LinearMipPoint = GL_LINEAR_MIPMAP_NEAREST,
	PointMipPoint = GL_NEAREST_MIPMAP_LINEAR
};

enum class EMaxAnisotropyLevel {
	Default = 1, 
	None = 1, 
	Low = 4, 
	Medium = 8, 
	High = 16
};

class Sampler
{
public:
	Sampler(Texture& texture, int texture_slot, EWrapMode wrap_mode = EWrapMode::Default, EFilteringMode filtering = EFilteringMode::Default, EMaxAnisotropyLevel max_anisotropy_level = EMaxAnisotropyLevel::Default);
	void Bind(EWrapMode wrap_mode, EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level);
	void SetWrapMode(EWrapMode wrap_mode);
	void SetFiltering(EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level);
	void SetMaxAnisotropyLevel(EMaxAnisotropyLevel max_anisotropy_level);
private:
	Texture& m_texture;
	int m_texture_slot;
	EWrapMode m_wrap_mode;
	EFilteringMode m_filtering;
	EMaxAnisotropyLevel m_max_anisotropy_level;
};

