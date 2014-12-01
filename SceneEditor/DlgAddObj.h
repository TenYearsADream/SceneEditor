#pragma once


// CDlgAddObj �Ի���

class CDlgAddObj : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddObj)

public:
	OBJ_TYPE m_obj_type;
	CString m_add_obj_name;
	CString m_objfile_name;
public:
	CDlgAddObj(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAddObj();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadioAddCube();
	afx_msg void OnBnClickedRadioAddCylinder();
	afx_msg void OnBnClickedRadioAddPrism();
	afx_msg void OnBnClickedRadioAddSphere();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBnClickedRadioAddObjfile();
};
