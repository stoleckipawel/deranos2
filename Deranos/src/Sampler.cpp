#include "pch.h"
#include "Sampler.h"

Sampler::Sampler(Texture& texture, int wrap_mode_x, int wrap_mode_y, int filtering)
	: m_texture(texture), m_wrap_mode_x(wrap_mode_x), m_wrap_mode_y(wrap_mode_y), m_filtering(filtering)
{
}

void Sampler::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_texture.GetId());
	glTexParameteri(GL_TEXTURE_2D, m_wrap_mode_x, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, m_wrap_mode_y, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_filtering);
	int mag_filter = ((m_filtering == GL_LINEAR_MIPMAP_NEAREST) || (m_filtering == GL_LINEAR_MIPMAP_LINEAR)) ? GL_LINEAR : GL_NEAREST;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);
}