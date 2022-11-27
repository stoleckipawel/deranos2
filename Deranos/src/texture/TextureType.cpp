#include "pch.h"
#include "TextureType.h"

TextureType::TextureType(int type, GLenum internal_format, GLenum format, bool generate_mips)
	: type(type), internal_format(internal_format), format(format), generate_mips(generate_mips)
{
	channel_num = format == GL_RGBA ? 4 :
		format == GL_RGB ? 3 :
		format == GL_RG ? 2 : 1;

	faces = type == GL_TEXTURE_CUBE_MAP ? 6 : 1;
}

