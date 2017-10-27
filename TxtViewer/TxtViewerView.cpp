
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
	ON_COMMAND(ID_FORMAT_SELECT_FONT, &CTxtViewerView::OnFormatSelectFont)
	ON_COMMAND(ID_TO_UPPERCASE, &CTxtViewerView::OnToUppercase)
	ON_COMMAND(ID_TO_LOWERCASE, &CTxtViewerView::OnToLowercase)
	ON_WM_CTLCOLOR_REFLECT()
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
	cs.style &= ~(ES_AUTOHSCROLL | WS_HSCROLL);	// ���û���

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


void CTxtViewerView::OnFormatSelectFont()
{
	// TODO: �ڴ���������������

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

//����֮���ʼ������

BOOL CTxtViewerView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	if (!CEditView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext))
	{
		return FALSE;
	}

	//��ʼ������
	m_font.CreatePointFont(90, "����");
	m_font.GetLogFont(&m_logfont);
	m_textColor = RGB(0, 0, 0);
	SetFont(&m_font);
	return TRUE;
}

//��д��Ϣ����

HBRUSH CTxtViewerView::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetTextColor(m_textColor);
	HBRUSH newHbr = CreateSolidBrush(RGB(255, 255, 255));
	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	return newHbr;
}


void CTxtViewerView::OnToUppercase()
{
	// TODO: �ڴ���������������
	CString temp;
	CEdit& m_cedit = GetEditCtrl();
	m_cedit.GetWindowText(temp);
	temp = temp.MakeUpper();
	m_cedit.SetWindowTextA(temp);
}


void CTxtViewerView::OnToLowercase()
{
	// TODO: �ڴ���������������
	CString temp;
	CEdit& m_cedit = GetEditCtrl();
	m_cedit.GetWindowText(temp);
	temp = temp.MakeLower();
	m_cedit.SetWindowTextA(temp);
}
