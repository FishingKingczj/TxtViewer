
// TxtViewerView.cpp : CTxtViewerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTxtViewerView 构造/析构

CTxtViewerView::CTxtViewerView()
{
	// TODO: 在此处添加构造代码

}

CTxtViewerView::~CTxtViewerView()
{
}

BOOL CTxtViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// CTxtViewerView 打印

BOOL CTxtViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CEditView 准备
	return CEditView::OnPreparePrinting(pInfo);
}

void CTxtViewerView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 开始打印
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CTxtViewerView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 结束打印
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CTxtViewerView 诊断

#ifdef _DEBUG
void CTxtViewerView::AssertValid() const
{
	CEditView::AssertValid();
}

void CTxtViewerView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CTxtViewerDoc* CTxtViewerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTxtViewerDoc)));
	return (CTxtViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CTxtViewerView 消息处理程序
