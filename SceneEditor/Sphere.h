//��״����

#pragma once
#include "Obj.h"
class CSphere :
	public CObj//����ע��
{
public:
	CSphere();
	~CSphere();

	GLint m_slices;
	GLint m_stacks;
	void draw();
};

