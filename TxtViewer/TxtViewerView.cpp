
// TxtViewerView.cpp : CTxtViewerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TxtViewer.h"
#endif

#include "TxtViewerDoc.h"
#include "TxtViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTxtViewerView

IMPLEMENT_DYNCREATE(CTxtViewerView, CEditView)

BEGIN_MESSAGE_MAP(CTxtViewerView, CEditView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTxtViewerView ����/����

CTxtViewerView::CTxtViewerView()
{
	// TODO: �ڴ˴���ӹ������

}

CTxtViewerView::~CTxtViewerView()
{
}

BOOL CTxtViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���û���

	return bPreCreated;
}


// CTxtViewerView ��ӡ

BOOL CTxtViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ׼��
	return CEditView::OnPreparePrinting(pInfo);
}

void CTxtViewerView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ��ʼ��ӡ
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CTxtViewerView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ������ӡ
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CTxtViewerView ���

#ifdef _DEBUG
void CTxtViewerView::AssertValid() const
{
	CEditView::AssertValid();
}

void CTxtViewerView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CTxtViewerDoc* CTxtViewerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTxtViewerDoc)));
	return (CTxtViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CTxtViewerView ��Ϣ�������
