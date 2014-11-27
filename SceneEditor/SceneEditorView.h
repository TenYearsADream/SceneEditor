
// SceneEditorView.h : CSceneEditorView ��Ľӿ�
//

#pragma once

enum VIEW_OP
{
	NONE,
	VIEW_ROTATE,
	VIEW_MOVE,
	
};

class CSceneEditorView : public CView
{
public:
	HGLRC m_hRC;    //Rendering Context��ɫ������
	CDC* m_pDC;        //Device Context�豸������
	BOOL InitializeOpenGL();    //Initialize OpenGL
	BOOL SetupPixelFormat();    //Set up the Pixel Format
	void RenderScene();            //Render the Scene
	//��ͼ
	bool m_lbutton_down;
	GLfloat m_eye_x;
	GLfloat m_eye_y;
	GLfloat m_eye_z;

	GLfloat m_center_x;
	GLfloat m_center_y;
	GLfloat m_center_z;
	VIEW_OP m_view_op;

	int m_temp_x;
	int m_temp_y;

protected: // �������л�����
	CSceneEditorView();
	DECLARE_DYNCREATE(CSceneEditorView)

// ����
public:
	CSceneEditorDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CSceneEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateMenuRotation(CCmdUI *pCmdUI);
	afx_msg void OnMenuMove();
	afx_msg void OnUpdateMenuMove(CCmdUI *pCmdUI);
	afx_msg void OnMenuRotation();
	afx_msg void OnMenuSelect();
	afx_msg void OnUpdateMenuSelect(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // SceneEditorView.cpp �еĵ��԰汾
inline CSceneEditorDoc* CSceneEditorView::GetDocument() const
   { return reinterpret_cast<CSceneEditorDoc*>(m_pDocument); }
#endif

