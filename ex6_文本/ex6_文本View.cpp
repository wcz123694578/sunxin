// ex6_文本View.cpp : implementation of the CEx6_View class
//

#include "stdafx.h"
#include "ex6_文本.h"

#include "ex6_文本Doc.h"
#include "ex6_文本View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx6_View

IMPLEMENT_DYNCREATE(CEx6_View, CView)

BEGIN_MESSAGE_MAP(CEx6_View, CView)
	//{{AFX_MSG_MAP(CEx6_View)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx6_View construction/destruction

CEx6_View::CEx6_View()
{
	// TODO: add construction code here
	m_strLine = "";
	m_ptOrigin = 0;
	m_nWidth = 0;
}

CEx6_View::~CEx6_View()
{
}

BOOL CEx6_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx6_View drawing

void CEx6_View::OnDraw(CDC* pDC)
{
	CEx6_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CString str("MFC文本");
	// ::TextOut(pDC->GetSafeHdc(), 10, 10, str, 7);   <-Win32方式
	CString str2(LoadString(IDS_OTOMAD));
	::TextOut(pDC->GetSafeHdc(), 10, 200, TEXT(str2), str2.GetLength());
	CSize sz = pDC->GetTextExtent(str);
	pDC->TextOut(50, 50, str);	// MFC方式

	pDC->BeginPath();
	pDC->Rectangle(50, 50, 50 + sz.cx, 50 + sz.cy);
	pDC->EndPath();

	pDC->SelectClipPath(RGN_AND);

	int i;
	CRect rect;
	GetClientRect(&rect);
	for (i = 0; i < rect.Width(); i += 50)	{
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, rect.Height());
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx6_View printing

BOOL CEx6_View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx6_View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx6_View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx6_View diagnostics

#ifdef _DEBUG
void CEx6_View::AssertValid() const
{
	CView::AssertValid();
}

void CEx6_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx6_Doc* CEx6_View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx6_Doc)));
	return (CEx6_Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx6_View message handlers

int CEx6_View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);
// 	m_bitmap.LoadBitmap(IDB_BITMAP1);
// 
// 	CreateCaret(&m_bitmap);

	ShowCaret();

	HWND hButton = ::CreateWindow(
		"BUTTON",
		"按钮",
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		60, 60, 100, 20,
		m_hWnd,
		(HMENU)1,
		(HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE),
		NULL
	);

	SetTimer(1, 100, NULL);
	return 0;
}

void CEx6_View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300, "Fixedsys", NULL);
	dc.SelectObject(&font);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);	// 获取行高
	if (nChar == 0x0d)	{
		m_strLine.Empty();
		m_ptOrigin.y += tm.tmHeight;
	} else if (nChar == 0x08)	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);
		dc.SetTextColor(clr);
	} else	{
		m_strLine += nChar;
	}
	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptOrigin.x + sz.cx;
	pt.y = m_ptOrigin.y;
	SetCaretPos(pt);
	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CEx6_View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}

void CEx6_View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_nWidth += 5;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect;
	rect.left = 0;
	rect.top 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255, 0, 0));
	CString str;
	str.LoadString(IDS_)
	// dc.DrawText()
	CView::OnTimer(nIDEvent);
}
