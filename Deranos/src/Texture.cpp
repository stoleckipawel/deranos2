#include "pch.h"
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Sampler.h"

Texture::Texture(const char* path, TextureType texture_type, bool flip)
	: m_texture_type(texture_type)
{
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);

	stbi_set_flip_vertically_on_load(flip);

	int channel_num;
	unsigned char* texture_data = stbi_load(path, &m_width, &m_height, &channel_num, 0);

	if (channel_num >= m_texture_type.channel_num)
	{
		if (channel_num > m_texture_type.channel_num)
			DERANOS_CORE_WARN("Texture channels have been truncated");

		if (texture_data)
		{
			CalcMipCount();
			glTexImage2D(GL_TEXTURE_2D, m_mip_count, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);

			if(m_texture_type.generate_mips)
				glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			DERANOS_CORE_WARN("Failed to load a texture");
		}
	}
	else
	{
		DERANOS_CORE_WARN("Texture contains less channels than expected");
	}

	stbi_image_free(texture_data);
}

void Texture::CalcMipCount()
{
	if (m_texture_type.generate_mips)
	{
		//# To do calculate mip levels based on resolution
		m_mip_count = 0;
	}
	else
	{
		m_mip_count = 0;
	}
}

unsigned int Texture::GetId()
{
	return m_id;
}

TextureType Texture::GetTextureType()
{
	return m_texture_type;
}

void Texture::Bind()
{
	Sampler(*this).Bind();
}

void Texture::Bind(int usermap)
{
	Bind();
}

