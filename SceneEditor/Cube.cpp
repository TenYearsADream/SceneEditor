#include "stdafx.h"
#include "Cube.h"


CCube::CCube()
{
}


CCube::~CCube()
{
}


void CCube::draw()
{
	SetMaterial();

	glPushMatrix();
	Transform();
	
	glBegin(GL_QUADS);
	/*
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	*/

	// ǰ��
	glNormal3f(0, 0, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);	// ������ı��ε�����

	// ����
	glNormal3f(0, 0, -1);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);	// ������ı��ε�����

	// ����
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);	// ������ı��ε�����

	// ����
	glNormal3f(0, -1, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, -0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);	// ������ı��ε�����

	// ����
	glNormal3f(1, 0, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);	// ������ı��ε�����

	// ����
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);	// ������ı��ε�����
	glEnd();

	glPopMatrix();
}
