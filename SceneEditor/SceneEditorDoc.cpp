
// SceneEditorDoc.cpp : CSceneEditorDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SceneEditor.h"
#endif

#include "SceneEditorDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSceneEditorDoc

IMPLEMENT_DYNCREATE(CSceneEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CSceneEditorDoc, CDocument)
	ON_COMMAND(ID_FILE_MY_OPEN, &CSceneEditorDoc::OnFileMyOpen)
	ON_COMMAND(ID_FILE_MY_SAVE, &CSceneEditorDoc::OnFileMySave)
END_MESSAGE_MAP()


// CSceneEditorDoc ����/����

CSceneEditorDoc::CSceneEditorDoc()
{
	// TODO:  �ڴ����һ���Թ������
	/*
	{
		CDocObj* pObj = new CDocObj(L"Բ��", CUBE);
		m_obj_list.push_back(pObj);
	}
	
	{
		CDocObj* pObj = new CDocObj(L"����", PRISM);
		pObj->m_obj->m_x = 3.0;
		m_obj_list.push_back(pObj);
	}
	*/
	{
		CLight* pLight = new CLight();
		pLight->m_name = CString("light_0");
		pLight->m_light_pos[0] = 0;
		pLight->m_light_pos[1] = 0;
		pLight->m_light_pos[2] = 5;
		m_light_list.push_back(pLight);
	}
	{
		CLight* pLight = new CLight();
		pLight->m_name = CString("light_1");
		pLight->m_light_pos[0] = 0;
		pLight->m_light_pos[1] = 0;
		pLight->m_light_pos[2] = -5;
		m_light_list.push_back(pLight);
	}
	 
}

CSceneEditorDoc::~CSceneEditorDoc()
{
}

BOOL CSceneEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	m_light_list.clear();
	m_obj_list.clear();
	CMainFrame *pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	if (pFrame == NULL)
		return TRUE;
	CSceneEditorView* pView = (CSceneEditorView*)pFrame->GetActiveView();
	if (pView == NULL)
		return TRUE;
	pFrame->remove_all_prop_list();
	pView->m_selected_is_valid = false;
	pView->m_need_update_light_tree = true;
	pView->m_need_update_obj_tree = true;
	return TRUE;
}




// CSceneEditorDoc ���л�

void CSceneEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CSceneEditorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CSceneEditorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CSceneEditorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSceneEditorDoc ���

#ifdef _DEBUG
void CSceneEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSceneEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSceneEditorDoc ����

CDocObj* CSceneEditorDoc::draw_property(CString name, CPropertiesWnd* pProperties)
{
	for (auto i = m_obj_list.begin(); i != m_obj_list.end(); i++)
	{
		if ((*i)->m_name == name)
		{
			pProperties->m_pObj = *i;
			pProperties->m_type = DRAW_OBJ;
			(*i)->draw_property(&pProperties->m_wndPropList);
			return *i;
		}
	}
	throw CString("CDocObj* CSceneEditorDoc::draw_property(CString name, CPropertiesWnd* pProperties)");

}

CLight* CSceneEditorDoc::draw_light_property(CString name, CPropertiesWnd* pProperties)
{
	for (auto i = m_light_list.begin(); i != m_light_list.end(); i++)
	{
		if ((*i)->m_name == name)
		{
			pProperties->m_pLight = *i;
			pProperties->m_type = DRAW_LIGHT;
			(*i)->draw_property(&pProperties->m_wndPropList);
			return *i;
		}
	}
	throw CString("CDocObj* CSceneEditorDoc::draw_property(CString name, CPropertiesWnd* pProperties)");
}

CDocObj* CSceneEditorDoc::add_obj(OBJ_TYPE type, CString name)
{
	CDocObj* pObj = new CDocObj(case_name_overlap(name, 0), type);
	if (pObj == NULL)
		throw CString("CDocObj* CSceneEditorDoc::add_obj(OBJ_TYPE type, CString name)");

	m_obj_list.push_back(pObj);
	return pObj;
}

CDocObj* CSceneEditorDoc::add_obj(CString name, CString file_name)
{
	CDocObj* pObj = new CDocObj(case_name_overlap(name, 0), file_name);
	if (pObj == NULL)
		throw CString("CDocObj* CSceneEditorDoc::add_obj(CString name, CString file_name)");

	m_obj_list.push_back(pObj);
	return pObj;
}

CString CSceneEditorDoc::case_name_overlap(CString name, int num)
{
	CString return_name;
	CString t_name;
	if (num == 0)
		t_name = name;
	else
		t_name.Format(_T("%s_%d"), name, num);

	for (auto i = m_obj_list.begin(); i != m_obj_list.end(); i++)
	{
		if ((*i)->m_name == t_name)
			return return_name = case_name_overlap(name, num + 1);
	}
	return t_name;
}

CLight* CSceneEditorDoc::add_light()
{
	CLight* pLight = new CLight();
	if (pLight == NULL)
		throw CString("CLight* CSceneEditorDoc::add_light()");
	/////////////////////////////////////////////////
	//����
	CString newname;
	if (m_light_list.size() == 0)
		newname = _T("light_0");
	else
	{
		auto pLastLight = m_light_list.rbegin();//���һ��
		CString lastname = (*pLastLight)->m_name;
		int find = lastname.Find(_T('_'));
		lastname = lastname.Right(lastname.GetLength() - find - 1);
		int a = _ttoi(lastname);
		newname.Format(_T("light_%d"), a + 1);
	}
	pLight->m_name = newname;
	/////////////////////////////////////////////////
	m_light_list.push_back(pLight);
	return pLight;
}

void CSceneEditorDoc::save_file(string filename)
{
	ofstream file;
	file.open(filename);
	if (!file)
		throw "void CSceneEditorDoc::save_file(string filename)";

	for (auto i = m_obj_list.begin(); i != m_obj_list.end(); i++)
	{
		switch ((*i)->m_type)
		{
		case CUBE:
			file << *((CCube*)((*i)->m_obj));
			break;
		case CYLINDER:
			file << *((CCylinder*)((*i)->m_obj));
			break;
		case PRISM:
			file << *((CPrism*)((*i)->m_obj));
			break;
		case SPHERE:
			file << *((CSphere*)((*i)->m_obj));
			break;
		case OBJ_FILE:
			file << *((CObjFile*)((*i)->m_obj));
			break;
		default:
			break;
		}
	}
	for (auto i = m_light_list.begin(); i != m_light_list.end(); i++)
	{
		file << *(*i);
	}


	file.close();
}
void CSceneEditorDoc::open_file(string filename)
{
	ifstream file;
	file.open(filename);
	if (!file)
		throw "void CSceneEditorDoc::open_file(string filename)";

	string temp;
	file >> temp;
	while (file.eof() == false)
	{
		if (temp == "<light>")
		{
			CLight* light;
			light = new CLight(file);
			m_light_list.push_back(light);
		}
		else
		{
			CObj* obj;
			CDocObj* pDocObj = new CDocObj();
			OBJ_TYPE type;
			if (temp == "<cube>")
			{
				obj = new CCube(file);
				type = CUBE;
			}
			else if (temp == "<cylinder>")
			{
				obj = new CCylinder(file);
				type = CYLINDER;
			}
			else if (temp == "<objfile>")
			{
				obj = new CObjFile(file);
				type = OBJ_FILE;
			}
			else if (temp == "<prism>")
			{
				obj = new CPrism(file);
				type = PRISM;
			}
			else if (temp == "<sphere>")
			{
				obj = new CSphere(file);
				type = SPHERE;
			}
			else
				throw "void CSceneEditorDoc::open_file(string filename)";
			CString name = case_name_overlap(CString(temp.c_str()));
			pDocObj->m_name = name;
			pDocObj->m_type = type;
			pDocObj->m_obj = obj;
			m_obj_list.push_back(pDocObj);
		}
		file >> temp;
	}
	CMainFrame *pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	CSceneEditorView* pView = (CSceneEditorView*)pFrame->GetActiveView();
	pView->m_need_update_light_tree = true;
	pView->m_need_update_obj_tree = true;
}

void CSceneEditorDoc::OnFileMyOpen()
{
	// TODO:  �ڴ���������������
	CString c_filename;
	string filename;
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		_T("3se"),
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("3d scene editor Files (*.3se)|*.3se|"),
		NULL);
	if (dlg.DoModal() == IDOK)
	{
		c_filename = dlg.GetPathName(); //�ļ�����������FilePathName��
		string filename = cstring_to_string(c_filename);
		open_file(filename);
	}
}


void CSceneEditorDoc::OnFileMySave()
{
	// TODO:  �ڴ���������������
	CString c_filename;
	string filename;
	CFileDialog dlg(FALSE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		_T("3se"),
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("3d scene editor Files (*.3se)|*.3se|"),
		NULL);
	if (dlg.DoModal() == IDOK)
	{
		c_filename = dlg.GetPathName(); //�ļ�����������FilePathName��
		string filename = cstring_to_string(c_filename);
		save_file(filename);
	}
}

string cstring_to_string(CString cstring)
{
	//M$�����Ĵ��ػ���
	//ע�⣺����n��len��ֵ��С��ͬ,n�ǰ��ַ�����ģ�len�ǰ��ֽڼ����
	int n = cstring.GetLength();    // n = 14, len = 18
	//��ȡ���ֽ��ַ��Ĵ�С����С�ǰ��ֽڼ����
	int len = WideCharToMultiByte(CP_ACP, 0, cstring, cstring.GetLength(), NULL, 0, NULL, NULL);
	//Ϊ���ֽ��ַ���������ռ䣬�����СΪ���ֽڼ���Ŀ��ֽ��ֽڴ�С
	char * pFileName = new char[len + 2];  //���ֽ�Ϊ��λ
	//���ֽڱ���ת���ɶ��ֽڱ���
	WideCharToMultiByte(CP_ACP, 0, cstring, cstring.GetLength(), pFileName, len, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, cstring, cstring.GetLength() + 1, pFileName, len + 1, NULL, NULL);
	pFileName[len + 1] = 0;  //���ֽ��ַ���'/0'����

	string s(pFileName);
	delete[] pFileName;
	return s;
}

