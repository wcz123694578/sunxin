// ex5_MFC消息映射Doc.cpp : implementation of the CEx5_MFCDoc class
//

#include "stdafx.h"
#include "ex5_MFC消息映射.h"

#include "ex5_MFC消息映射Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCDoc

IMPLEMENT_DYNCREATE(CEx5_MFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx5_MFCDoc, CDocument)
	//{{AFX_MSG_MAP(CEx5_MFCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCDoc construction/destruction

CEx5_MFCDoc::CEx5_MFCDoc()
{
	// TODO: add one-time construction code here

}

CEx5_MFCDoc::~CEx5_MFCDoc()
{
}

BOOL CEx5_MFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCDoc serialization

void CEx5_MFCDoc::Serialize(CArchive& ar)
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
// CEx5_MFCDoc diagnostics

#ifdef _DEBUG
void CEx5_MFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx5_MFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCDoc commands
