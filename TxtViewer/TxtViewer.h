
// TxtViewer.h : TxtViewer Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTxtViewerApp:
// �йش����ʵ�֣������ TxtViewer.cpp
//

class CTxtViewerApp : public CWinApp
{
public:
	CTxtViewerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTxtViewerApp theApp;
