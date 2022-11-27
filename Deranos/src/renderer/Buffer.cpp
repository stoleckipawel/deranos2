#include "pch.h"
#include "Buffer.h"

Buffer::Buffer(uint format, uint width, uint height)//format
	: width(width), height(height), m_format(format)
{
	glGenTextures(1, &m_id);
	Bind();
	Activate();

	//zbuffer & stencil attachment
	/*
	unsigned int rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
	*/
}

void Buffer::Activate()
{
	glTexImage2D(GL_TEXTURE_2D, 0, m_format, width, height, 0, m_format, GL_UNSIGNED_BYTE, nullptr);
}

void Buffer::Bind(uint usermap)
{
	glActiveTexture(GL_TEXTURE0 + usermap);
	glBindTexture(GL_TEXTURE_2D, m_id);
}

Buffer::~Buffer()
{
	glDeleteTextures(1, &m_id);
}
