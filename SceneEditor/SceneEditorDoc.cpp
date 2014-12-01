
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
END_MESSAGE_MAP()


// CSceneEditorDoc ����/����

CSceneEditorDoc::CSceneEditorDoc()
{
	// TODO:  �ڴ����һ���Թ������
	{
		CDocObj* pObj = new CDocObj(L"Բ��", CUBE);
		m_obj_list.push_back(pObj);
	}
	
	{
		CDocObj* pObj = new CDocObj(L"����", PRISM);
		pObj->m_obj->m_x = 3.0;
		m_obj_list.push_back(pObj);
	}
	
	{
		//cube ����������ʹ�ã���Ϊʹ����glut��
		//CDocObj* pObj = new CDocObj(L"Բ��", CYLINDER);
		//m_obj_list.push_back(pObj);
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