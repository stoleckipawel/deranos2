#include "pch.h"
#include "TextureTypes.h"

TextureType TextureTypes::Default()
{
	return TextureType(GL_TEXTURE_2D, GL_RGBA8, GL_RGBA, false);
}

TextureType TextureTypes::Cubemap()
{
	return TextureType(GL_TEXTURE_CUBE_MAP, GL_RGB8, GL_RGB, true);
}

TextureType TextureTypes::Diffuse()
{
	return TextureType(GL_TEXTURE_2D, GL_RGB8, GL_RGB, true);
}

TextureType TextureTypes::Normal()
{
	return TextureType(GL_TEXTURE_2D, GL_RG8_SNORM, GL_RG, true);
}

TextureType TextureTypes::Specular()
{
	return TextureType(GL_TEXTURE_2D, GL_RGB8, GL_RGB, true);
}

TextureType TextureTypes::Roughness()
{
	return TextureType(GL_TEXTURE_2D, GL_R8, GL_RED, true);
}

TextureType TextureTypes::Metalic()
{
	return TextureType(GL_TEXTURE_2D, GL_R8, GL_RED, true);
}
