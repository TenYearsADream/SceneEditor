#include "stdafx.h"
#include "Light.h"


CLight::CLight()
{
	m_color[0] = 1;
	m_color[1] = 1;
	m_color[2] = 1;
	m_color[3] = 1;

	m_light_pos[0] = 0;
	m_light_pos[1] = 0;
	m_light_pos[2] = 0;
	m_light_pos[3] = 1;

	m_on = true;
}


CLight::~CLight()
{
}

void CLight::draw_light(int num)
{
	if (m_on == false)
		return;
	if (num < 0 || num>7)
		throw "void CLight::draw_light(int num),ֻ���а˸��ƹ⣡";
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, m_color);
	glLightfv(GL_LIGHT0 + num, GL_POSITION, m_light_pos);
	glLightfv(GL_LIGHT0 + num, GL_DIFFUSE, m_color);
	glEnable(GL_LIGHT0 + num);
}

void CLight::draw_property(CMFCPropertyGridCtrl* PropList)
{
	PropList->RemoveAll();

	PropList->EnableHeaderCtrl(FALSE);
	PropList->EnableDescriptionArea();
	PropList->SetVSDotNetLook();

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("��Դ"));

	CMFCPropertyGridProperty* pLocation = new CMFCPropertyGridProperty(_T("����λ��"), 0, TRUE);
	CMFCPropertyGridProperty* p = new CMFCPropertyGridProperty(_T("X"), (_variant_t)m_light_pos[0], _T("����������X��λ��"));
	pLocation->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("Y"), (_variant_t)m_light_pos[1], _T("����������Y��λ��"));
	pLocation->AddSubItem(p);
	p = new CMFCPropertyGridProperty(_T("Z"), (_variant_t)m_light_pos[2], _T("����������Z��λ��"));
	pLocation->AddSubItem(p);
	pLocation->AllowEdit(FALSE);
	pGroup1->AddSubItem(pLocation);

	int rgb[] = { m_color[0] * 255.0, m_color[1] * 255.0, m_color[2] * 255.0 };
	CMFCPropertyGridColorProperty* pColorProp = new CMFCPropertyGridColorProperty(_T("��Դ��ɫ"), RGB(rgb[0], rgb[1], rgb[2]), NULL, _T("��ǰ��Դ����ɫ"));
	pColorProp->EnableOtherButton(_T("����..."));
	pColorProp->EnableAutomaticButton(_T("Ĭ��"), ::GetSysColor(COLOR_3DFACE));
	pGroup1->AddSubItem(pColorProp);


	PropList->AddProperty(pGroup1);
}

void CLight::change_value(CMFCPropertyGridProperty* pProp)
{
	
	CString name = pProp->GetName();  //���ı�Ĳ�����
	COleVariant t = pProp->GetValue(); //�ı�֮���ֵ
	if (name == "X")
	{
		m_light_pos[0] = GLfloat(t.fltVal);
		return;
	}
	if (name == "Y")
	{
		m_light_pos[1] = GLfloat(t.fltVal);
		return;
	}
	if (name == "Z")
	{
		m_light_pos[2] = GLfloat(t.fltVal);
		return;
	}
	if (name == "��Դ��ɫ")
	{
		COLORREF c = t.lVal;
		m_color[0] = (c & 0xff) / 255.0;
		m_color[1] = (c >> 8 & 0xff) / 255.0;
		m_color[2] = (c >> 16 & 0xff) / 255.0;
		return;
	}
}

