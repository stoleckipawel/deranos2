#pragma once

enum texture_type
{
	color,
	diffuse,
	normal,
	specular,
	roughness,
	tangent,
	metalic,
	height
};

class Texture
{
public:
	Texture(const char* path, bool flip);
	unsigned int GetId();
	void SetTextureType(texture_type type);
	texture_type GetTextureType();
	void Bind(int usermap);
	void Bind();
private:
	unsigned int  m_id;
	texture_type m_texture_type;
	int m_width;
	int m_height;
	int m_channel_num;

};

