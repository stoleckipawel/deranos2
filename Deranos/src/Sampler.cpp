#include "pch.h"
#include "Sampler.h"
#include "TextureTypes.h"

Sampler::Sampler(Texture& texture, int texture_slot, EWrapMode wrap_mode, EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level)
	: m_texture(texture), m_texture_slot(texture_slot)
{
	Bind(wrap_mode, filtering, max_anisotropy_level);
}

void Sampler::Bind(EWrapMode wrap_mode, EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level)
{
	glActiveTexture(GL_TEXTURE0 + m_texture_slot);
	glBindTexture(m_texture.GetTextureType().type, m_texture.GetId());
	SetWrapMode(wrap_mode);
	SetFiltering(filtering, max_anisotropy_level);
}

void Sampler::SetWrapMode(EWrapMode wrap_mode)
{
	//If texture is cube map force clamp wrap mode, temporary hack should be forced in other way
	if (m_texture.GetTextureType().type == TextureTypes::Cubemap().type)
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, int(EWrapMode::Clamp));
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, int(EWrapMode::Clamp));
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, int(EWrapMode::Clamp));
	}
	else
	{
		m_wrap_mode = wrap_mode;
		glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_WRAP_S, int(m_wrap_mode));
		glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_WRAP_T, int(m_wrap_mode));
	}	
}

void Sampler::SetFiltering(EFilteringMode filtering, EMaxAnisotropyLevel max_anisotropy_level)
{
	m_filtering = filtering;
	glBindTexture(m_texture.GetTextureType().type, m_texture.GetId());
	//-Minification
	glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_MIN_FILTER, int(filtering));
	//-Magnification
	int mag_filter = ((filtering == EFilteringMode::LinearMipPoint) || (filtering == EFilteringMode::LinearMipLinear)) ? GL_LINEAR : GL_NEAREST;
	glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_MAG_FILTER, mag_filter);
	//Anisotropy level
	SetMaxAnisotropyLevel(max_anisotropy_level);
}

void Sampler::SetMaxAnisotropyLevel(EMaxAnisotropyLevel max_anisotropy_level)
{
	m_max_anisotropy_level = max_anisotropy_level;
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, int(m_max_anisotropy_level));
}
