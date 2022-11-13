#include "pch.h"
#include "TextureType.h"

TextureType::TextureType(GLenum format, int channel_num, int dimensions, bool generate_mips)
	: format(format), channel_num(channel_num), dimensions(dimensions), generate_mips(generate_mips)
{
}

