#include "pch.h"
#include "TextureTypes.h"

TextureType TextureTypes::Default()
{
	return TextureType(GL_RGB, 3, 2, false);
}

TextureType TextureTypes::Diffuse()
{
	return TextureType(GL_RGB, 3, 2, true);
}

TextureType TextureTypes::Normal()
{
	return TextureType(GL_RGB, 3, 2, true);
}

TextureType TextureTypes::Specular()
{
	return TextureType(GL_RGB, 3, 2, true);
}

TextureType TextureTypes::Roughness()
{
	return TextureType(GL_RED, 1, 2, true);
}
