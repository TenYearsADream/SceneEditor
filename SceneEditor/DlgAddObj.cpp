// DlgAddObj.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SceneEditor.h"
#include "DlgAddObj.h"
#include "afxdialogex.h"


// CDlgAddObj �Ի���

IMPLEMENT_DYNAMIC(CDlgAddObj, CDialogEx)

CDlgAddObj::CDlgAddObj(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddObj::IDD, pParent)
	, m_add_obj_name(_T("Ĭ������"))
{

}

CDlgAddObj::~CDlgAddObj()
{
}

void CDlgAddObj::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADD_OBJ_NAME, m_add_obj_name);
}


BEGIN_MESSAGE_MAP(CDlgAddObj, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_ADD_CUBE, &CDlgAddObj::OnBnClickedRadioAddCube)
	ON_BN_CLICKED(IDC_RADIO_ADD_CYLINDER, &CDlgAddObj::OnBnClickedRadioAddCylinder)
	ON_BN_CLICKED(IDC_RADIO_ADD_PRISM, &CDlgAddObj::OnBnClickedRadioAddPrism)
	ON_BN_CLICKED(IDC_RADIO_ADD_SPHERE, &CDlgAddObj::OnBnClickedRadioAddSphere)
	ON_BN_CLICKED(IDC_RADIO_ADD_OBJFILE, &CDlgAddObj::OnBnClickedRadioAddObjfile)
END_MESSAGE_MAP()


// CDlgAddObj ��Ϣ�������


void CDlgAddObj::OnBnClickedRadioAddCube()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_obj_type = CUBE;
	if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
		m_add_obj_name = "cube";
	UpdateData(FALSE);
}



void CDlgAddObj::OnBnClickedRadioAddCylinder()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_obj_type = CYLINDER;
	if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
		m_add_obj_name = "cylinder";
	UpdateData(FALSE);
}


void CDlgAddObj::OnBnClickedRadioAddPrism()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_obj_type = PRISM;
	if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
		m_add_obj_name = "prism";
	UpdateData(FALSE);
}


void CDlgAddObj::OnBnClickedRadioAddSphere()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_obj_type = SPHERE;
	if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
		m_add_obj_name = "sphere";
	UpdateData(FALSE);
}


BOOL CDlgAddObj::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	switch (m_obj_type)
	{
	case CUBE:
		CheckDlgButton(IDC_RADIO_ADD_CUBE, BST_CHECKED);
		if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
			m_add_obj_name = "cube";
		break;
	case CYLINDER:
		CheckDlgButton(IDC_RADIO_ADD_CYLINDER, BST_CHECKED);
		if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
			m_add_obj_name = "cylinder";
		break;
	case PRISM:
		CheckDlgButton(IDC_RADIO_ADD_PRISM, BST_CHECKED);
		if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
			m_add_obj_name = "prism";
		break;
	case SPHERE:
		CheckDlgButton(IDC_RADIO_ADD_SPHERE, BST_CHECKED);
		if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
			m_add_obj_name = "sphere";
		break;
	case OBJ_FILE:
		//����д��û�д���ģ���Ϊ�ڶ�����ӵ�ʱ����������´��ļ��Ļ����ᵼ��file_nameΪ�գ�����
		CheckDlgButton(IDC_RADIO_ADD_CUBE, BST_CHECKED);
		if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
			m_add_obj_name = "cube";
		m_obj_type = CUBE;
		break;
	default:
		CheckDlgButton(IDC_RADIO_ADD_CUBE, BST_CHECKED);
		if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
			m_add_obj_name = "cube";
		break;
	}
	UpdateData(TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDlgAddObj::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void CDlgAddObj::OnBnClickedRadioAddObjfile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("obj Files (*.obj)|*.obj|"),
		NULL);

	if (dlg.DoModal() == IDOK)
	{
		m_objfile_name = dlg.GetPathName(); //�ļ�����������FilePathName��
	}
	else
	{
		CheckDlgButton(IDC_RADIO_ADD_OBJFILE, BST_UNCHECKED);
		switch (m_obj_type)
		{
		case CUBE:
			CheckDlgButton(IDC_RADIO_ADD_CUBE, BST_CHECKED);
			break;
		case CYLINDER:
			CheckDlgButton(IDC_RADIO_ADD_CYLINDER, BST_CHECKED);
			break;
		case PRISM:
			CheckDlgButton(IDC_RADIO_ADD_PRISM, BST_CHECKED);
			break;
		case SPHERE:
			CheckDlgButton(IDC_RADIO_ADD_SPHERE, BST_CHECKED);
			break;
		case OBJ_FILE:
			CheckDlgButton(IDC_RADIO_ADD_OBJFILE, BST_CHECKED);
			break;
		default:
			break;
		}

		return;
	}

	m_obj_type = OBJ_FILE;
	if (m_add_obj_name == "Ĭ������" || m_add_obj_name == "cube" || m_add_obj_name == "cylinder" || m_add_obj_name == "prism" || m_add_obj_name == "sphere" || m_add_obj_name == "obj_file")
		m_add_obj_name = "obj_file";
	UpdateData(FALSE);
}
