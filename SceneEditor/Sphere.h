//��״����

#pragma once
#include "Obj.h"
class CSphere :
	public CObj//����ע��
{
public:
	CSphere();
	~CSphere();
	//�뾶
	GLfloat m_r;
	GLint m_slices;
	GLint m_stacks;
	void draw();
	void mark();
	friend ostream& operator<<(ostream& out, CSphere sphere);

};

