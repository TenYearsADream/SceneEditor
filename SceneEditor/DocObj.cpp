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
	m_obj->draw();
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
}