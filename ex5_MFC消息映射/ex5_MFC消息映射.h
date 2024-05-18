// ex5_MFC消息映射.h : main header file for the EX5_MFC消息映射 application
//

#if !defined(AFX_EX5_MFC_H__6640FFCF_37C5_48E9_87C9_FAF60C372168__INCLUDED_)
#define AFX_EX5_MFC_H__6640FFCF_37C5_48E9_87C9_FAF60C372168__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCApp:
// See ex5_MFC消息映射.cpp for the implementation of this class
//

class CEx5_MFCApp : public CWinApp
{
public:
	CEx5_MFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx5_MFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx5_MFCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX5_MFC_H__6640FFCF_37C5_48E9_87C9_FAF60C372168__INCLUDED_)
