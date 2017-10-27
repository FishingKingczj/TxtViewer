
// TxtViewerView.h : CTxtViewerView 类的接口
//

#pragma once


class CTxtViewerView : public CEditView
{
protected: // 仅从序列化创建
	CTxtViewerView();
	DECLARE_DYNCREATE(CTxtViewerView)

// 特性
public:
	CTxtViewerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
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

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFormatSelectFont();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};

#ifndef _DEBUG  // TxtViewerView.cpp 中的调试版本
inline CTxtViewerDoc* CTxtViewerView::GetDocument() const
   { return reinterpret_cast<CTxtViewerDoc*>(m_pDocument); }
#endif

