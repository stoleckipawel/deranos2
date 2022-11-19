#pragma once
class TextureType
{
public:
	TextureType(int type, GLenum format, int channel_num, int dimensions, bool generate_mips, int faces);

	const int type;//2d/3d/cubemap etc
	const GLenum format;
	const int channel_num;
	const int dimensions;
	const bool generate_mips;
	const int faces;
	//mip filter option(kaiser, default etc)
};

