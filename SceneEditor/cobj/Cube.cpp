#include "stdafx.h"
#include "Cube.h"


CCube::CCube()
{
}

CCube::CCube(istream& file) :CCube()
{
	string temp;
	file >> temp;

	while (temp != "</cube>")
	{
		if (temp == "<obj>")
			CObj::load(file);
		else
			throw "CCube::CCube(istream& file)";
		file >> temp;
	}
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
	//glRotatef(90, 1, 0, 0);
	//DrawScene(0);
}

void CCube::mark()
{
	glPushMatrix();
	Transform();
	glScalef(1.1, 1.1, 1.1);

	glDisable(GL_LIGHTING);
	glColor3f(0, 1, 1);

	glBegin(GL_LINES);

	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glEnd();

	glEnable(GL_LIGHTING);
	glPopMatrix();
}

ostream& operator<<(ostream& out, CCube cube)
{
	out << "<cube>" << endl;
	out << (CObj)cube;
	out << "</cube>" << endl;
	out << endl;
	return out;
}

bool CCube::is_collision(float x, float y, float z)
{
	float dx = x - m_x;
	float dy = y - m_y;
	float dz = z - m_z;

	MATRIX4X4 m;
	VECTOR4D v(dx, dy, dz, 1);
	{
		glPushMatrix();
		glLoadIdentity();
		glScalef(m_l, m_w, m_h);
		glRotatef(m_angle_x, 1, 0, 0);
		glRotatef(m_angle_y, 0, 1, 0);
		glRotatef(m_angle_z, 0, 0, 1);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
		glPopMatrix();
	}
	VECTOR4D result = m.GetInverse()*v;
	if (abs(result.x) > 0.5)
		return false;
	if (abs(result.y) > 0.5)
		return false;
	if (abs(result.z) > 0.5)
		return false;
	return true;
}