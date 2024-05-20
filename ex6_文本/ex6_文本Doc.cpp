// ex6_文本Doc.cpp : implementation of the CEx6_Doc class
//

#include "stdafx.h"
#include "ex6_文本.h"

#include "ex6_文本Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx6_Doc

IMPLEMENT_DYNCREATE(CEx6_Doc, CDocument)

BEGIN_MESSAGE_MAP(CEx6_Doc, CDocument)
	//{{AFX_MSG_MAP(CEx6_Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx6_Doc construction/destruction

CEx6_Doc::CEx6_Doc()
{
	// TODO: add one-time construction code here

}

CEx6_Doc::~CEx6_Doc()
{
}

BOOL CEx6_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx6_Doc serialization

void CEx6_Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx6_Doc diagnostics

#ifdef _DEBUG
void CEx6_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx6_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx6_Doc commands
