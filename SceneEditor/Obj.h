#pragma once

//VC�� math.h ���� M_PI ����ѧ������Ҫ���� #include <math.h> ǰ�涨�� _USE_MATH_DEFINES ��
#define _USE_MATH_DEFINES
#include <cmath>

#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
class CObj
{
public:
	//λ��
	GLfloat m_x, m_y, m_z;
	//�����
	GLfloat m_l, m_w, m_h;
	//�Ƕ�
	GLfloat m_angle_x, m_angle_y, m_angle_z;
	GLfloat m_ambient[4];
	GLfloat m_diffuse[4];
	GLfloat m_specular[4];
	GLfloat m_shininess;

	CObj();
	~CObj();

	virtual void draw() = 0;
protected:
	void SetMaterial();
	void Transform();
};
