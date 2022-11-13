#pragma once
class TextureType
{
public:
	TextureType(GLenum format, int channel_num, int dimensions, bool generate_mips);

	const GLenum format;
	const int channel_num;
	const int dimensions;
	const bool generate_mips;
	//mip filter option(kaiser, default etc)
};

