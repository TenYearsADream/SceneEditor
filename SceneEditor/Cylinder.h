//Բ����

#pragma once
#include "Obj.h"
class CCylinder :
	public CObj
{
public:
	CCylinder();
	~CCylinder();
private:
	GLUquadricObj* m_quadricObj;
public:
	//�µװ뾶
	GLfloat m_baseRadius;
	//�ϵװ뾶
	GLfloat m_topRadius;
	//�߶�
	GLfloat m_height;
	//�㶮��
	GLint m_slices;
	//�㶮��
	GLint m_stacks;

	void draw();
private:
	void DrawCircleArea(float cx, float cy, float cz, float r, int num_segments);
};

