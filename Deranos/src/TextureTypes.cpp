#include "pch.h"
#include "TextureTypes.h"

TextureType TextureTypes::Default()
{
	return TextureType(GL_TEXTURE_2D, GL_RGB, 3, 2, false, 1);
}

TextureType TextureTypes::Cubemap()
{
	return TextureType(GL_TEXTURE_CUBE_MAP, GL_RGB, 3, 2, false, 6);
}

TextureType TextureTypes::Diffuse()
{
	return TextureType(GL_TEXTURE_2D, GL_RGB, 3, 2, true, 1);
}

TextureType TextureTypes::Normal()
{
	return TextureType(GL_TEXTURE_2D, GL_RGB, 3, 2, true, 1);
}

TextureType TextureTypes::Specular()
{
	return TextureType(GL_TEXTURE_2D, GL_RGB, 3, 2, true, 1);
}

TextureType TextureTypes::Roughness()
{
	return TextureType(GL_TEXTURE_2D, GL_RED, 1, 2, true, 1);
}
