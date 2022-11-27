#pragma once

class TextureType
{
public:
	TextureType(int type, GLenum internal_format, GLenum format, bool generate_mips);

	const int type;//2d/3d/cubemap etc
	const GLenum internal_format;
	const GLenum format;
	int channel_num;
	const bool generate_mips;
	int faces;
	//mip filter option(kaiser, default etc)
};

