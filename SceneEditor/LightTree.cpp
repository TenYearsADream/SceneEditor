// LightTree.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SceneEditor.h"
#include "LightTree.h"


// CLightTree

IMPLEMENT_DYNAMIC(CLightTree, CTreeCtrl)

CLightTree::CLightTree()
{

}

CLightTree::~CLightTree()
{
}


BEGIN_MESSAGE_MAP(CLightTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CLightTree::OnTvnSelchanged)
END_MESSAGE_MAP()



// CLightTree ��Ϣ�������




BOOL CLightTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO:  �ڴ����ר�ô����/����û���

	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}


void CLightTree::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString obj_name = GetItemText(pNMTreeView->itemNew.hItem);
	CMainFrame *pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->draw_property(obj_name, DRAW_LIGHT);
	pFrame->m_obj_or_light_name = obj_name;
	pFrame->m_draw_type = DRAW_LIGHT;
	CSceneEditorView* pView = (CSceneEditorView*)pFrame->GetActiveView();
	/*ȡ�������ѡ��
	HTREEITEM hItem = pFrame->m_wndFileView.m_wndFileView.GetSelectedItem();
	pFrame->m_wndFileView.m_wndFileView.SetItemState(hItem, 0, TVIS_SELECTED);
	*/
	pView->Invalidate(FALSE);
	*pResult = 0;
}
