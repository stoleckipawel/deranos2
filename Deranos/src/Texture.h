#pragma once
#include "TextureTypes.h"

class Texture
{
public:
	Texture(const char* path, TextureType texture_type = TextureTypes::Default(), bool flip = true);
	unsigned int GetId();
	TextureType GetTextureType();
private:
	unsigned int  m_id;
	int m_width;
	int m_height;
	int m_mip_count;
	const TextureType m_texture_type;
};

