// ex5_MFCÏûÏ¢Ó³ÉäDoc.h : interface of the CEx5_MFCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX5_MFCDOC_H__4CEDC3CD_BEBF_4552_A961_95F807AB1BEE__INCLUDED_)
#define AFX_EX5_MFCDOC_H__4CEDC3CD_BEBF_4552_A961_95F807AB1BEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx5_MFCDoc : public CDocument
{
protected: // create from serialization only
	CEx5_MFCDoc();
	DECLARE_DYNCREATE(CEx5_MFCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx5_MFCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx5_MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx5_MFCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX5_MFCDOC_H__4CEDC3CD_BEBF_4552_A961_95F807AB1BEE__INCLUDED_)
