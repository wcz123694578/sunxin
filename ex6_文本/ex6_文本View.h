// ex6_文本View.h : interface of the CEx6_View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX6_VIEW_H__61891904_5444_4050_A9B5_CF4ABB2C1ABA__INCLUDED_)
#define AFX_EX6_VIEW_H__61891904_5444_4050_A9B5_CF4ABB2C1ABA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx6_View : public CView
{
protected: // create from serialization only
	CEx6_View();
	DECLARE_DYNCREATE(CEx6_View)

// Attributes
public:
	CEx6_Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx6_View)
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
	CPoint m_ptOrigin;
	CString m_strLine;
	virtual ~CEx6_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx6_View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_nWidth;
	CBitmap m_bitmap;
};

#ifndef _DEBUG  // debug version in ex6_文本View.cpp
inline CEx6_Doc* CEx6_View::GetDocument()
   { return (CEx6_Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX6_VIEW_H__61891904_5444_4050_A9B5_CF4ABB2C1ABA__INCLUDED_)
