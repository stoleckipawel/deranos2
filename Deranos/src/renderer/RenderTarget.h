#pragma once

enum class ECLearFlags { Color = GL_COLOR_BUFFER_BIT, Depth = GL_DEPTH_BUFFER_BIT, Stencil = GL_STENCIL_BUFFER_BIT };

class RenderTarget
{
public:
	RenderTarget();
	~RenderTarget();
	void Clear(glm::vec4 clear_color, ECLearFlags flags);
	void SetRenderTargetView();
private:
	void Validate();
	void Attach(uint texture_id, uint mip_level = 0);
	unsigned int m_id;
};


#define BackBufferID 0
static class BackBuffer
{
public:
	static void SetRenderTargetView();
	static void Clear(glm::vec4 clear_color);
};
