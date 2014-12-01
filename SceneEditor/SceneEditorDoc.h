
// SceneEditorDoc.h : CSceneEditorDoc ��Ľӿ�
//


#pragma once

#include <list>
using namespace std;
#include "DocObj.h"

#include "PropertiesWnd.h"

class CSceneEditorDoc : public CDocument
{
protected: // �������л�����
	CSceneEditorDoc();
	DECLARE_DYNCREATE(CSceneEditorDoc)

// ����
public:
	list<CDocObj*> m_obj_list;
// ����
public:
	CDocObj* draw_property(CString name, CPropertiesWnd* pProperties);
	CDocObj* add_obj(OBJ_TYPE type, CString name);
	CDocObj* add_obj(CString name, CString file_name);
	CString case_name_overlap(CString name, int num);

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
};
