#pragma once
class Buffer
{
public:
	Buffer(uint format, uint width, uint height);
	~Buffer();
	void Bind(uint usermap = 0);
	void Activate();
	int width;
	int height;
private:
	unsigned int m_id;
	uint m_format;
};

