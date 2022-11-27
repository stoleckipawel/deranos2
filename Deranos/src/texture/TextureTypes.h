#pragma once 
#include "TextureType.h"

class TextureTypes
{
public:
	static TextureType Default();
	static TextureType Cubemap();
	static TextureType Diffuse();
	static TextureType Normal();
	static TextureType Specular();
	static TextureType Roughness();
	static TextureType Metalic();
};


