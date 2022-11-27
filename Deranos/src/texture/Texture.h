#pragma once
#include "TextureTypes.h"

class Texture
{
public:
	Texture(int type, GLenum internal_format, GLenum format, uint width, uint height);
	Texture(const char* path, TextureType texture_type, bool flip = true);
	void Bind();
	uint GetId();
	TextureType GetTextureType();
private:
	void LoadTexture();
	void LoadTexture(const char* path, int target);
	void LoadTextureCubemap();
	void CreateTexture(unsigned char* texture_data, int target);

	const char* m_path;
	uint m_id;
	int m_width;
	int m_height;
	const TextureType m_texture_type;
	bool m_flip;
};

