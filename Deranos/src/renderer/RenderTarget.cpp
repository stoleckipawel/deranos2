#include "pch.h"
#include "RenderTarget.h"

void RenderTarget::SetRenderTargetView(std::vector<Texture> renderTargets)
{
	uint id;
	glGenFramebuffers(1, &id);
	glBindFramebuffer(GL_FRAMEBUFFER, id);

	uint mip = 0;//To do expose mips

	for (int i = 0; i < renderTargets.size(); i++)
	{
		Attach(renderTargets[i].GetId(), mip, i);
	}

	Validate();
	glBindFramebuffer(GL_FRAMEBUFFER, id);
}

void RenderTarget::Attach(uint texture_id, uint mip_level, int rt_index)
{
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + rt_index, GL_TEXTURE_2D, texture_id, mip_level);
}

void RenderTarget::Validate()
{
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		DERANOS_CORE_ERROR("FRAMEBUFFER:: Framebuffer is not complete!");
}

void RenderTarget::Clear(glm::vec4 clear_color, ECLearFlags flags)
{
	glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
	glClear((uint)flags);
}

void RenderTarget::Clear(glm::vec4 clear_color)
{
	Clear(clear_color, ECLearFlags::Color);
}

void BackBuffer::SetRenderTargetView()
{
	glBindFramebuffer(GL_FRAMEBUFFER, BackBufferID);
}

void BackBuffer::Clear(glm::vec4 clear_color)
{
	SetRenderTargetView();
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear((uint)ECLearFlags::Color);
}