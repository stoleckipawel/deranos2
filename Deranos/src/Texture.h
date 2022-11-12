#pragma once
#include "TextureTypes.h"



class Texture
{
public:
	Texture(const char* path, TextureType texture_type = TextureTypes::Default(), bool flip = true);
	unsigned int GetId();
	TextureType GetTextureType();
	void Bind(int usermap);
	void Bind();
private:
	void CalcMipCount();

	unsigned int  m_id;
	TextureType m_texture_type;
	int m_width;
	int m_height;
	int m_mip_count;
};

