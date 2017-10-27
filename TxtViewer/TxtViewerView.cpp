
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
	ON_COMMAND(ID_FORMAT_SELECT_FONT, &CTxtViewerView::OnFormatSelectFont)
	ON_COMMAND(ID_TO_UPPERCASE, &CTxtViewerView::OnToUppercase)
	ON_COMMAND(ID_TO_LOWERCASE, &CTxtViewerView::OnToLowercase)
	ON_WM_CTLCOLOR_REFLECT()
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
	cs.style &= ~(ES_AUTOHSCROLL | WS_HSCROLL);	// 启用换行

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


void CTxtViewerView::OnFormatSelectFont()
{
	// TODO: 在此添加命令处理程序代码

	CFontDialog m_fontDlg(&m_logfont, CF_EFFECTS);
	m_fontDlg.m_cf.rgbColors = m_textColor;
	if (m_fontDlg.DoModal() == IDOK)
	{
		m_fontDlg.GetCurrentFont(&m_logfont);
		m_font.DeleteObject();
		m_font.CreateFontIndirect(&m_logfont);
		m_textColor = m_fontDlg.GetColor();
		SetFont(&m_font);
	}
}

//创建之后初始化字体

BOOL CTxtViewerView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (!CEditView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext))
	{
		return FALSE;
	}

	//初始化字体
	m_font.CreatePointFont(90, "宋体");
	m_font.GetLogFont(&m_logfont);
	m_textColor = RGB(0, 0, 0);
	SetFont(&m_font);
	return TRUE;
}

//重写消息反射

HBRUSH CTxtViewerView::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性
	pDC->SetTextColor(m_textColor);
	HBRUSH newHbr = CreateSolidBrush(RGB(255, 255, 255));
	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	return newHbr;
}


void CTxtViewerView::OnToUppercase()
{
	// TODO: 在此添加命令处理程序代码
	CString temp;
	CEdit& m_cedit = GetEditCtrl();
	m_cedit.GetWindowText(temp);
	temp = temp.MakeUpper();
	m_cedit.SetWindowTextA(temp);
}


void CTxtViewerView::OnToLowercase()
{
	// TODO: 在此添加命令处理程序代码
	CString temp;
	CEdit& m_cedit = GetEditCtrl();
	m_cedit.GetWindowText(temp);
	temp = temp.MakeLower();
	m_cedit.SetWindowTextA(temp);
}
