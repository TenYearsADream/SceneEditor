
#include "stdafx.h"
#include "ViewTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CViewTree::OnTvnSelchanged)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree ��Ϣ�������

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}

void CViewTree::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString obj_name = GetItemText(pNMTreeView->itemNew.hItem);
	CMainFrame *pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->draw_property(obj_name, DRAW_OBJ);
	pFrame->m_obj_or_light_name = obj_name;
	pFrame->m_draw_type = DRAW_OBJ;
	CSceneEditorView* pView = (CSceneEditorView*)pFrame->GetActiveView();
	/*ȡ�������ѡ��
	HTREEITEM hItem = pFrame->m_wndClassView.m_wndLightView.GetSelectedItem();
	pFrame->m_wndClassView.m_wndLightView.SetItemState(hItem, 0, TVIS_SELECTED);
	*/
	pView->Invalidate(FALSE);
	*pResult = 0;
}
