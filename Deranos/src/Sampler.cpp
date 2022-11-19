#include "pch.h"
#include "Sampler.h"
#include "TextureTypes.h"

Sampler::Sampler(Texture& texture, int texture_slot, int wrap_mode, int filtering)
	: m_texture(texture), m_texture_slot(texture_slot), m_wrap_mode(wrap_mode), m_filtering(filtering)
{
	Bind();
}

void Sampler::Bind()
{
	//Active texture slot
	glActiveTexture(GL_TEXTURE0 + m_texture_slot);
	//Bind texture
	glBindTexture(m_texture.GetTextureType().type, m_texture.GetId());
	//Set Tiling properties
	glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_WRAP_S, m_wrap_mode);
	glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_WRAP_T, m_wrap_mode);
	if(m_texture.GetTextureType().type == TextureTypes::Cubemap().type)
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	//Set Filtering params
	//-Minification
	glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_MIN_FILTER, m_filtering);
	//-Magnification
	int mag_filter = ((m_filtering == GL_LINEAR_MIPMAP_NEAREST) || (m_filtering == GL_LINEAR_MIPMAP_LINEAR)) ? GL_LINEAR : GL_NEAREST;
	glTexParameteri(m_texture.GetTextureType().type, GL_TEXTURE_MAG_FILTER, mag_filter);
	

	//#To do anisotropy(needs extensions) glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);
}