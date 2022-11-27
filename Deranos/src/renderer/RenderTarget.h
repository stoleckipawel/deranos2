#pragma once
#include "Texture.h"

enum class ECLearFlags { Color = GL_COLOR_BUFFER_BIT, Depth = GL_DEPTH_BUFFER_BIT, Stencil = GL_STENCIL_BUFFER_BIT };

static class RenderTarget
{
public:
	static void Clear(glm::vec4 clear_color, ECLearFlags flags);
	static void Clear(glm::vec4 clear_color);
	static void SetRenderTargetView(std::vector<Texture> renderTargets);
	
private:
	static void Validate();
	static void Attach(uint texture_id, uint mip_level, int rt_index);
};


#define BackBufferID 0
static class BackBuffer
{
public:
	static void SetRenderTargetView();
	static void Clear(glm::vec4 clear_color);
};
