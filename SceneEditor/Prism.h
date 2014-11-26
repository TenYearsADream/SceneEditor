#pragma once
#include "Obj.h"
class CPrism :
	public CObj
{
public:
	CPrism();
	~CPrism();

	GLint m_edge;
	//�µװ뾶
	GLfloat m_baseRadius;
	//�ϵװ뾶
	GLfloat m_topRadius;
	//�߶�
	GLfloat m_height;

	void draw();
private:
	void DrawBottom(GLfloat h, GLfloat r);
	void DrawSide();
};