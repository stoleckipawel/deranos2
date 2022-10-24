#pragma once

class Texture
{
public:
	Texture(const char* path, bool flip);
	unsigned int GetId();
	void Bind();
private:
	unsigned int  m_id;
	int m_width;
	int m_height;
	int m_channel_num;
};

