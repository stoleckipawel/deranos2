#pragma once
#include "TextureTypes.h"

class Texture
{
public:
	Texture(int type, GLenum internal_format, GLenum format, uint width, uint height);
	Texture(const char* path, TextureType texture_type = TextureTypes::Default(), bool flip = true);
	~Texture();
	unsigned int GetId();
	TextureType GetTextureType();
	
private:
	void LoadTexture();
	void LoadTexture(const char* path, int target);
	void LoadTextureCubemap();
	void CreateTexture(unsigned char* texture_data, int target);

	const char* m_path;
	unsigned int  m_id;
	int m_width;
	int m_height;
	int m_mip_count;
	const TextureType m_texture_type;
	bool m_flip;

	std::vector<const char*> m_cubemap_faces;
};

