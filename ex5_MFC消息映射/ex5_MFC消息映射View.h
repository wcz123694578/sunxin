// ex5_MFC消息映射View.h : interface of the CEx5_MFCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX5_MFCVIEW_H__748D87C7_CB12_467A_AAE8_5557B9632464__INCLUDED_)
#define AFX_EX5_MFCVIEW_H__748D87C7_CB12_467A_AAE8_5557B9632464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx5_MFCView : public CView
{
protected: // create from serialization only
	CEx5_MFCView();
	DECLARE_DYNCREATE(CEx5_MFCView)

// Attributes
public:
	CEx5_MFCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx5_MFCView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx5_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx5_MFCView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bDraw;
	CPoint m_pOrigin;
	CPoint m_pOld;
};

#ifndef _DEBUG  // debug version in ex5_MFC消息映射View.cpp
inline CEx5_MFCDoc* CEx5_MFCView::GetDocument()
   { return (CEx5_MFCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX5_MFCVIEW_H__748D87C7_CB12_467A_AAE8_5557B9632464__INCLUDED_)
