#include "pch.h"
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Sampler.h"

Texture::Texture(const char* path, TextureType texture_type, bool flip)
	: m_path(path), m_texture_type(texture_type), m_flip(flip)
{
	glGenTextures(1, &m_id);
	glBindTexture(m_texture_type.type, m_id);

	if (texture_type.type == TextureTypes::Cubemap().type)
	{
		LoadTextureCubemap();
	}
	else
	{
		LoadTexture();
	}

	if (m_texture_type.generate_mips)
		glGenerateMipmap(m_texture_type.type);
}

void Texture::LoadTextureCubemap()
{
	stbi_set_flip_vertically_on_load(false);
	//right, left, top, bottom, front, back
	m_cubemap_faces.push_back("right");
	m_cubemap_faces.push_back("left");
	m_cubemap_faces.push_back("top");
	m_cubemap_faces.push_back("bottom");
	m_cubemap_faces.push_back("front");
	m_cubemap_faces.push_back("back");

	//Load all faces of the cubemap
	for (int i = 0; i < 6; i++)
	{

		std::string path = m_path;//path to skybox, char* to string
		path.append(m_cubemap_faces[i]);//add face name
		path.append(".png");

		LoadTexture(path.c_str(), GL_TEXTURE_CUBE_MAP_POSITIVE_X + i);
	}
}

void Texture::LoadTexture()
{
	stbi_set_flip_vertically_on_load(m_flip);
	LoadTexture(m_path, m_texture_type.type);
}

void Texture::LoadTexture(const char* path, int target)
{
	int channel_num;
	unsigned char* texture_data = stbi_load(path, &m_width, &m_height, &channel_num, 0);

	if(texture_data)
	{
		if (channel_num >= m_texture_type.channel_num)
		{
			CreateTexture(texture_data, target);
		}
		else
		{
			//that's a horrible way to add strings, I need to learn a better one
			std::string warning_message = "Texture contains less channels than expected: ";
			warning_message.append(path);
			DERANOS_CORE_WARN(warning_message);
			//#To do: fill with 0.0s missing channels
		}
	}
	else
	{
		std::string warning_message = "Failed to load, path: ";
		warning_message.append(path);
		DERANOS_CORE_WARN(warning_message);
	}

	stbi_image_free(texture_data);
}

void Texture::CreateTexture(unsigned char* texture_data, int target)
{
	if (!texture_data)
	{
		DERANOS_CORE_WARN("Failed to load a texture");
		return;
	}
		
	glTexImage2D(target, 0, m_texture_type.format, m_width, m_height, 0, m_texture_type.format, GL_UNSIGNED_BYTE, texture_data);
}

unsigned int Texture::GetId()
{
	return m_id;
}

TextureType Texture::GetTextureType()
{
	return m_texture_type;
}



