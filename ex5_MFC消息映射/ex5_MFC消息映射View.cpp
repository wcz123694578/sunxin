// ex5_MFC消息映射View.cpp : implementation of the CEx5_MFCView class
//

#include "stdafx.h"
#include "ex5_MFC消息映射.h"

#include "ex5_MFC消息映射Doc.h"
#include "ex5_MFC消息映射View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCView

IMPLEMENT_DYNCREATE(CEx5_MFCView, CView)

BEGIN_MESSAGE_MAP(CEx5_MFCView, CView)
	//{{AFX_MSG_MAP(CEx5_MFCView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCView construction/destruction

CEx5_MFCView::CEx5_MFCView()
{
	// TODO: add construction code here
	m_bDraw = FALSE;
	m_pOld = 0;
}

CEx5_MFCView::~CEx5_MFCView()
{
}

BOOL CEx5_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCView drawing

void CEx5_MFCView::OnDraw(CDC* pDC)
{
	CEx5_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCView printing

BOOL CEx5_MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx5_MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx5_MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCView diagnostics

#ifdef _DEBUG
void CEx5_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CEx5_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx5_MFCDoc* CEx5_MFCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx5_MFCDoc)));
	return (CEx5_MFCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx5_MFCView message handlers

void CEx5_MFCView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_pOrigin = m_pOld = point;
	m_bDraw = TRUE;
	CView::OnLButtonDown(nFlags, point);
}

void CEx5_MFCView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/* Win32 API的方式 */
// 	HDC hdc = ::GetDC(m_hWnd);
// 	::MoveToEx(hdc, m_pOrigin.x, m_pOrigin.y, NULL);
// 	::LineTo(hdc, point.x, point.y);
// 	::ReleaseDC(m_hWnd, hdc);

/* CDC的方式 */
// 	CDC *pdc = GetDC();
// 	pdc->MoveTo(m_pOrigin);
// 	pdc->LineTo(point);
// 	ReleaseDC(pdc);

// 	CClientDC dc(GetParent());
// 	dc.MoveTo(m_pOrigin);
// 	dc.LineTo(point);

// 	CPen pen(PS_DASH, 1, RGB(255, 0, 0));
// 	CWindowDC dc(this);
// 	CPen *pOldPen = dc.SelectObject(&pen);
// 	// SelectObject(dc, pen);
// 	dc.MoveTo(m_pOrigin);
// 	dc.LineTo(point);
// 
// 	dc.SelectObject(pOldPen);
// 	

// 	CBrush brush(RGB(255, 255, 0));
// 	CWindowDC dc(this);
// 	dc.FillRect(CRect(m_pOrigin, point), &brush);

// 	CBitmap bitmap;
// 	bitmap.LoadBitmap(IDB_BITMAP1);
// 	CBrush brush(&bitmap);


// 	CClientDC dc(this);
// 	// dc.FillRect(CRect(m_pOrigin, point), &brush);
// 	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
// 	CBrush *pOldBrush = dc.SelectObject(pBrush);
// 	
// 	dc.Rectangle(CRect(m_pOrigin, point));
// 	dc.SelectObject(pOldBrush);

	m_bDraw = FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CEx5_MFCView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *pOldPen = dc.SelectObject(&pen);
	if (m_bDraw)	{
		dc.SetROP2(R2_BLACK);
		// dc.SetROP2(R2_MERGENOTPEN);
		dc.MoveTo(m_pOrigin);
		// dc.LineTo(point);
		dc.LineTo(m_pOld);
		// dc.MoveTo(m_pOrigin);
		dc.MoveTo(m_pOld);
		dc.LineTo(point);
		// m_pOrigin = point;
		m_pOld = point;
		
	}
	dc.SelectObject(pOldPen);
	CView::OnMouseMove(nFlags, point);
}
