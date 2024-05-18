// ex2View.cpp : implementation of the CEx2View class
//

#include "stdafx.h"
#include "ex2.h"

#include "ex2Doc.h"
#include "ex2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx2View

IMPLEMENT_DYNCREATE(CEx2View, CView)

BEGIN_MESSAGE_MAP(CEx2View, CView)
	//{{AFX_MSG_MAP(CEx2View)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx2View construction/destruction

CEx2View::CEx2View()
{
	// TODO: add construction code here

}

CEx2View::~CEx2View()
{
}

BOOL CEx2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx2View drawing

void CEx2View::OnDraw(CDC* pDC)
{
	CEx2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx2View printing

BOOL CEx2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx2View diagnostics

#ifdef _DEBUG
void CEx2View::AssertValid() const
{
	CView::AssertValid();
}

void CEx2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx2Doc* CEx2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx2Doc)));
	return (CEx2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx2View message handlers

int CEx2View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_btn.Create("ÎÒµÄ°´Å¥", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 
				CRect(0, 0, 100, 100), this, 123);
	// m_btn.ShowWindow(SW_SHOWNORMAL);

	return 0;
}
