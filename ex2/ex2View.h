// ex2View.h : interface of the CEx2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX2VIEW_H__6B6E9D05_C254_46B3_9AA3_2403E9D7A1E7__INCLUDED_)
#define AFX_EX2VIEW_H__6B6E9D05_C254_46B3_9AA3_2403E9D7A1E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx2View : public CView
{
protected: // create from serialization only
	CEx2View();
	DECLARE_DYNCREATE(CEx2View)

// Attributes
public:
	CEx2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx2View)
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
	virtual ~CEx2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ex2View.cpp
inline CEx2Doc* CEx2View::GetDocument()
   { return (CEx2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX2VIEW_H__6B6E9D05_C254_46B3_9AA3_2403E9D7A1E7__INCLUDED_)
