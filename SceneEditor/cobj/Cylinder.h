//Բ����

#pragma once
#include "Obj.h"
class CCylinder :
	public CObj
{
public:
	CCylinder();
	CCylinder(istream& file);
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
	void mark();
	bool is_collision(float x, float y, float z);
	friend ostream& operator<<(ostream& out, CCylinder cylinder);
private:
	void DrawCircleArea(float cx, float cy, float cz, float r, int num_segments);
};

