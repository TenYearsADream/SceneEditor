
// SceneEditorDoc.h : CSceneEditorDoc ��Ľӿ�
//


#pragma once

#include <list>
using namespace std;
#include "DocObj.h"
#include "Light.h"
#include "PropertiesWnd.h"

class CSceneEditorDoc : public CDocument
{
protected: // �������л�����
	CSceneEditorDoc();
	DECLARE_DYNCREATE(CSceneEditorDoc)

// ����
public:
	list<CDocObj*> m_obj_list;
	list<CLight*> m_light_list;
// ����
public:
	CDocObj* draw_property(CString name, CPropertiesWnd* pProperties);
	CLight* draw_light_property(CString name, CPropertiesWnd* pProperties);
	CDocObj* add_obj(OBJ_TYPE type, CString name);
	CDocObj* add_obj(CString name, CString file_name);
	CLight* add_light();
	CString case_name_overlap(CString name, int num = 0);

	void save_file(string filename);
	void open_file(string filename);

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CSceneEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileMyOpen();
	afx_msg void OnFileMySave();
};

string cstring_to_string(CString cstring);