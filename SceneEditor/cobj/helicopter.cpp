#include "stdafx.h"
#include "helicopter.h"

#define BITMAP_ID 0x4D42

helicopter::helicopter()
{
	//����
	m_rotor1.m_l = 4;
	m_rotor1.m_w = 0.1;
	m_rotor1.m_h = 0.01;

	m_rotor2.m_l = 0.1;
	m_rotor2.m_w = 4;
	m_rotor2.m_h = 0.01;
	//�������
	cylinder1.m_topRadius = 0.05;
	cylinder1.m_baseRadius= 0.05;
	cylinder1.m_height = 0.3;

	//��
	body.m_angle_x = 90;
	body.m_angle_y = 90;
	body.m_edge = 6;
	body.m_baseRadius = 0.5;
	body.m_topRadius= 0.5;

	body2.m_x = 1;
	body2.m_angle_x = 90;
	body2.m_angle_y = 90;
	body2.m_edge = 6;
	body2.m_baseRadius = 0.5;
	body2.m_topRadius = 0.2;
	body2.m_height = 0.5;

	//sphere.m_r = 0.5;
	sphere.m_r = 0.45;
	sphere.m_l = 1.5;
	//β��
	tail.m_l = 2.5;
	tail.m_h = 0.05;
	tail.m_w = 0.1;
	
	prism.m_angle_x = 90;
	prism.m_angle_z = 180;
	prism.m_l = 0.1;
	prism.m_w = 0.1;
	prism.m_y = 0.5;
	prism.m_x = -0.3;

	tail2.m_angle_x = 90;
	tail2.m_height = 0.01;
	tail2.m_baseRadius = 0.3;
	tail2.m_topRadius= 0.3;
	tail2.m_z = 0.17;
	tail2.m_x = -0.4;

	glGenTextures(2, m_texture);
	texload("texture/glass.bmp", m_texture[0]);
	texload("texture/camouflage.bmp", m_texture[1]);

}


helicopter::~helicopter()
{
}

void helicopter::draw()
{
	SetMaterial();
	glPushMatrix();
	Transform();
	{
		glPushMatrix();
		glTranslatef(0, 0, 0.7);
		m_rotor1.draw();
		m_rotor2.draw();
		glTranslatef(0, 0, -0.3);
		cylinder1.draw();
		glPopMatrix();
	}
	{
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, m_texture[0]);
		glEnable(GL_TEXTURE_2D);
		sphere.draw();
		body.draw();
		body2.draw();
		glTranslatef(2.5, 0, 0);
		tail.draw();
		glTranslatef(1.25, 0, 0);
		prism.draw();
		tail2.draw();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}



	glPopMatrix();

	rotate(15);
}

void helicopter::mark()
{

}

void helicopter::rotate(int delta_angle)
{
	m_rotor1.m_angle_z = (int)(m_rotor1.m_angle_z + delta_angle) % 360;
	m_rotor2.m_angle_z = (int)(m_rotor2.m_angle_z + delta_angle) % 360;
}


void helicopter::texload(const char *filename, GLuint texture)
{
	BITMAPINFOHEADER bitmapInfoHeader;                                 // bitmap��Ϣͷ

	m_bitmapData = LoadBitmapFile(filename, &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, texture);
	// ָ����ǰ����ķŴ�/��С���˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D,
		0, 	    //mipmap���(ͨ��Ϊ����ʾ���ϲ�) 
		GL_RGB,	//����ϣ���������к졢�̡�������
		bitmapInfoHeader.biWidth, //��������������n�����б߿�+2 
		bitmapInfoHeader.biHeight, //����߶ȣ�������n�����б߿�+2 
		0, //�߿�(0=�ޱ߿�, 1=�б߿�) 
		GL_RGB,	//bitmap���ݵĸ�ʽ
		GL_UNSIGNED_BYTE, //ÿ����ɫ���ݵ�����
		m_bitmapData);	//bitmap����ָ��  
}

unsigned char* helicopter::LoadBitmapFile(const char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE *filePtr;	// �ļ�ָ��
	BITMAPFILEHEADER bitmapFileHeader;	// bitmap�ļ�ͷ
	unsigned char	*bitmapImage;		// bitmapͼ������
	int	imageIdx = 0;		// ͼ��λ������
	unsigned char	tempRGB;	// ��������

	// �ԡ�������+����ģʽ���ļ�filename 
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL) return NULL;
	// ����bitmap�ļ�ͼ
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
	// ��֤�Ƿ�Ϊbitmap�ļ�
	if (bitmapFileHeader.bfType != BITMAP_ID) {
		throw ("Error in LoadBitmapFile: the file is not a bitmap file\n");
	}

	// ����bitmap��Ϣͷ
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
	// ���ļ�ָ������bitmap����
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// Ϊװ��ͼ�����ݴ����㹻���ڴ�
	//������������+1�����HEAP CORRUPTION DETECTED����
	bitmapImage = new unsigned char[bitmapInfoHeader->biSizeImage + 1];
	// ��֤�ڴ��Ƿ񴴽��ɹ�
	if (!bitmapImage) {
		throw ("Error in LoadBitmapFile: memory error\n");
	}

	// ����bitmapͼ������
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// ȷ�϶���ɹ�
	if (bitmapImage == NULL) {
		throw ("Error in LoadBitmapFile: memory error\n");
	}

	//����bitmap�б���ĸ�ʽ��BGR�����潻��R��B��ֵ���õ�RGB��ʽ
	for (imageIdx = 0; imageIdx < (int)bitmapInfoHeader->biSizeImage; imageIdx += 3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
	// �ر�bitmapͼ���ļ�
	fclose(filePtr);
	return bitmapImage;
}
