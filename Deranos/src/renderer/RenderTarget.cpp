#include "pch.h"
#include "RenderTarget.h"

RenderTarget::RenderTarget()
{
	glGenFramebuffers(1, &m_id);
	glBindFramebuffer(GL_FRAMEBUFFER, m_id);
	/*
	Attach(texture_id);
	SetRenderTargetView();
	*/
}

void RenderTarget::Attach(uint texture_id, uint mip_level)
{
	//MRT -> for each texture attachement 0,1,2,3

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id, mip_level);
	//GL_DEPTH_ATTACHMENT, GL_DEPTH_STENCIL_ATTACHMENT
}

void RenderTarget::Validate()
{
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		DERANOS_CORE_ERROR("FRAMEBUFFER:: Framebuffer is not complete!");
}

void RenderTarget::SetRenderTargetView()
{
	Validate();
	glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}

void RenderTarget::Clear(glm::vec4 clear_color, ECLearFlags flags)
{
	SetRenderTargetView();
	glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
	glClear((uint)flags);
}

RenderTarget::~RenderTarget()
{
	glDeleteFramebuffers(1, &m_id);
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