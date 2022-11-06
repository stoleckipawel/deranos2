#pragma once

enum texture_type
{
	none,
	diffuse,
	specular,
	roughness,
	normal,
	tangent,
	metalic,
	height
};

class Texture
{
public:
	Texture(const char* path, bool flip);
	unsigned int GetId();
	texture_type GetTextureType();
	void Bind();
private:
	unsigned int  m_id;
	texture_type m_texture_type;
	int m_width;
	int m_height;
	int m_channel_num;
};

