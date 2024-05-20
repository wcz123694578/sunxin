// ex6_ÎÄ±¾Doc.h : interface of the CEx6_Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX6_DOC_H__644A9622_5065_4E9F_A75A_02990BD4F639__INCLUDED_)
#define AFX_EX6_DOC_H__644A9622_5065_4E9F_A75A_02990BD4F639__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx6_Doc : public CDocument
{
protected: // create from serialization only
	CEx6_Doc();
	DECLARE_DYNCREATE(CEx6_Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx6_Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx6_Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx6_Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX6_DOC_H__644A9622_5065_4E9F_A75A_02990BD4F639__INCLUDED_)
