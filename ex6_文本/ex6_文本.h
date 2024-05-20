// ex6_文本.h : main header file for the EX6_文本 application
//

#if !defined(AFX_EX6__H__31928BDE_2609_4F51_B7DA_C0C98F88CA52__INCLUDED_)
#define AFX_EX6__H__31928BDE_2609_4F51_B7DA_C0C98F88CA52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx6_App:
// See ex6_文本.cpp for the implementation of this class
//

class CEx6_App : public CWinApp
{
public:
	CEx6_App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx6_App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx6_App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX6__H__31928BDE_2609_4F51_B7DA_C0C98F88CA52__INCLUDED_)
