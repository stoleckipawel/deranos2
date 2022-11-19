#include "pch.h"
#include "TextureType.h"

TextureType::TextureType(int type = GL_TEXTURE_2D, GLenum format = GL_RGBA, int channel_num = 4, int dimensions = 2, bool generate_mips = false, int faces = 1)
	: type(type), format(format), channel_num(channel_num), dimensions(dimensions), generate_mips(generate_mips), faces(faces)
{
}

