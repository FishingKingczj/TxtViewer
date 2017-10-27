
// TxtViewerView.h : CTxtViewerView ��Ľӿ�
//

#pragma once


class CTxtViewerView : public CEditView
{
protected: // �������л�����
	CTxtViewerView();
	DECLARE_DYNCREATE(CTxtViewerView)

// ����
public:
	CTxtViewerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTxtViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CFont m_font;
	LOGFONT m_logfont;
	COLORREF m_textColor;

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFormatSelectFont();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};

#ifndef _DEBUG  // TxtViewerView.cpp �еĵ��԰汾
inline CTxtViewerDoc* CTxtViewerView::GetDocument() const
   { return reinterpret_cast<CTxtViewerDoc*>(m_pDocument); }
#endif

