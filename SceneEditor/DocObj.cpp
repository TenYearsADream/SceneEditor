
#include "stdafx.h"
#include "DocObj.h"
CDocObj::CDocObj(CString name, OBJ_TYPE type)
{
	m_name = name;
	m_type = type;
	switch (type)
	{
	case CUBE:
		m_obj = new CCube();
		break;
	case CYLINDER:
		m_obj = new CCylinder();
		break;
	case PRISM:
		m_obj = new CPrism();
		break;
	case SPHERE:
		m_obj = new CSphere();
		break;
	default:
		throw CString("CDocObj(OBJ_TYPE type)");
		break;
	}

	m_whether_texture = false;
	m_bitmapData = NULL;
}

CDocObj::CDocObj(CString name, CString file_name)
{

}


CDocObj::~CDocObj()
{
	delete m_obj;
}

void CDocObj::draw_property(CMFCPropertyGridCtrl* PropList)
{
	PropList->RemoveAll();
	draw_property_obj(PropList);
	switch (m_type)
	{
	case CUBE:
		draw_property_cube(PropList);
		break;
	case CYLINDER:
		draw_property_cylinder(PropList);
		break;
	case PRISM:
		draw_property_prism(PropList);
		break;
	case SPHERE:
		draw_property_sphere(PropList);
		break;
	default:
		throw CString("draw_property");
		break;
	}
}

void CDocObj::draw()
{
	if (m_whether_texture == true)
	{
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glEnable(GL_TEXTURE_2D);
	}
	m_obj->draw();
	glDisable(GL_TEXTURE_2D);
}

void CDocObj::draw_property_obj(CMFCPropertyGridCtrl* PropList)
{
	PropList->EnableHeaderCtrl(FALSE);
	PropList->EnableDescriptionArea();
	PropList->SetVSDotNetLook();

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("ͨ��"));

	CMFCPropertyGridProperty* pLocation = new CMFCPropertyGridProperty(_T("����λ��"), 0, TRUE);
	CMFCPropertyGridProperty* p = new CMFCPropertyGridProperty(_T("X"), (_variant_t)m_obj->m_x, _T("����������X��λ��"));
	pLocation->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("Y"), (_variant_t)m_obj->m_y, _T("����������Y��λ��"));
	pLocation->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("Z"), (_variant_t)m_obj->m_z, _T("����������Z��λ��"));
	pLocation->AddSubItem(p);
	pLocation->AllowEdit(FALSE);
	pGroup1->AddSubItem(pLocation);



	CMFCPropertyGridProperty* pSize = new CMFCPropertyGridProperty(_T("�����С"), 0, TRUE);
	p = new CMFCPropertyGridProperty(_T("��"), (_variant_t)m_obj->m_l, _T("����ĳ���"));
	pSize->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("��"), (_variant_t)m_obj->m_w, _T("����Ŀ��"));
	pSize->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("��"), (_variant_t)m_obj->m_h, _T("����ĸ߶�"));
	pSize->AddSubItem(p);
	pSize->AllowEdit(FALSE);
	pGroup1->AddSubItem(pSize);


	CMFCPropertyGridProperty* pAngle = new CMFCPropertyGridProperty(_T("������ת�Ƕ�"), 0, TRUE);
	p = new CMFCPropertyGridProperty(_T("X��Ƕ�"), (_variant_t)m_obj->m_angle_x, _T("�����X�᷽����ת�Ƕ�"));
	pAngle->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("Y��Ƕ�"), (_variant_t)m_obj->m_angle_y, _T("�����Y�᷽����ת�Ƕ�"));
	pAngle->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("Z��Ƕ�"), (_variant_t)m_obj->m_angle_z, _T("�����Z�᷽����ת�Ƕ�"));
	pAngle->AddSubItem(p);
	pAngle->AllowEdit(FALSE);
	pGroup1->AddSubItem(pAngle);

	PropList->AddProperty(pGroup1);

	CMFCPropertyGridProperty* pGroup2 = new CMFCPropertyGridProperty(_T("����"));
	CMFCPropertyGridProperty* whether_texture = new CMFCPropertyGridProperty(_T("�Ƿ�����"), (_variant_t)m_whether_texture, _T("ָ�Ƿ�ѡ������"));
	pGroup2->AddSubItem(whether_texture);

	if (m_whether_texture == true)
	{
		pGroup2->AddSubItem(new CMFCPropertyGridFileProperty(_T("ѡ�������ļ�"), TRUE, m_texture_file_name, _T("bmp"), NULL, _T("bmp Files(*.bmp)|*.bmp|"), _T("ѡ��bmp�ļ�")));//ѡ���ļ���ť  
	}

	PropList->AddProperty(pGroup2);

}
void CDocObj::draw_property_cube(CMFCPropertyGridCtrl* PropList)
{

}
void CDocObj::draw_property_cylinder(CMFCPropertyGridCtrl* PropList)
{

}
void CDocObj::draw_property_prism(CMFCPropertyGridCtrl* PropList)
{

}
void CDocObj::draw_property_sphere(CMFCPropertyGridCtrl* PropList)
{

}

void CDocObj::change_value(CMFCPropertyGridProperty* pProp)
{
	CString name = pProp->GetName();  //���ı�Ĳ�����
	COleVariant t = pProp->GetValue(); //�ı�֮���ֵ
	//m_obj->m_x += 1;
	if (name == "X")
	{
		m_obj->m_x = GLfloat(t.fltVal);
		return;
	}
	if (name == "Y")
	{
		m_obj->m_y = GLfloat(t.fltVal);
		return;
	}
	if (name == "Z")
	{
		m_obj->m_z = GLfloat(t.fltVal);
		return;
	}

	if (name == "��")
	{
		m_obj->m_l = GLfloat(t.fltVal);
		return;
	}
	if (name == "��")
	{
		m_obj->m_w = GLfloat(t.fltVal);
		return;
	}
	if (name == "��")
	{
		m_obj->m_h = GLfloat(t.fltVal);
		return;
	}

	if (name == "X��Ƕ�")
	{
		m_obj->m_angle_x = GLfloat(t.fltVal);
		return;
	}
	if (name == "Y��Ƕ�")
	{
		m_obj->m_angle_y = GLfloat(t.fltVal);
		return;
	}
	if (name == "X��Ƕ�")
	{
		m_obj->m_angle_z = GLfloat(t.fltVal);
		return;
	}
	if (name == "�Ƿ�����")
	{
		m_whether_texture = (t.boolVal != 0);
		return;
	}
	if (name == "ѡ�������ļ�")
	{
		m_texture_file_name = t;
		if (m_bitmapData != NULL)
		{
			delete[] m_bitmapData;
			m_bitmapData = NULL;
		}

		//M$�Ҳ����ү�������ô�鷳
		//ע�⣺����n��len��ֵ��С��ͬ,n�ǰ��ַ�����ģ�len�ǰ��ֽڼ����
		int n = m_texture_file_name.GetLength();    // n = 14, len = 18
		//��ȡ���ֽ��ַ��Ĵ�С����С�ǰ��ֽڼ����
		int len = WideCharToMultiByte(CP_ACP, 0, m_texture_file_name, m_texture_file_name.GetLength(), NULL, 0, NULL, NULL);
		//Ϊ���ֽ��ַ���������ռ䣬�����СΪ���ֽڼ���Ŀ��ֽ��ֽڴ�С
		char * pFileName = new char[len + 1];  //���ֽ�Ϊ��λ
		//���ֽڱ���ת���ɶ��ֽڱ���
		WideCharToMultiByte(CP_ACP, 0, m_texture_file_name, m_texture_file_name.GetLength(), pFileName, len, NULL, NULL);
		WideCharToMultiByte(CP_ACP, 0, m_texture_file_name, m_texture_file_name.GetLength() + 1, pFileName, len + 1, NULL, NULL);
		pFileName[len + 1] = 0;  //���ֽ��ַ���'/0'����

		texload(pFileName);

		return;
	}
}

void CDocObj::texload(const char *filename)
{
	BITMAPINFOHEADER bitmapInfoHeader;                                 // bitmap��Ϣͷ

	m_bitmapData = LoadBitmapFile(filename, &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, m_texture);
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

unsigned char* CDocObj::LoadBitmapFile(const char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
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
		throw CString("Error in LoadBitmapFile: the file is not a bitmap file\n");
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
		throw CString("Error in LoadBitmapFile: memory error\n");
	}

	// ����bitmapͼ������
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
	// ȷ�϶���ɹ�
	if (bitmapImage == NULL) {
		throw CString("Error in LoadBitmapFile: memory error\n");
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