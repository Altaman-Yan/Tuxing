// DrawALineDoc.h : interface of the CDrawALineDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWALINEDOC_H__227A1E09_1B0A_48D3_815B_1FDBE9A41ADC__INCLUDED_)
#define AFX_DRAWALINEDOC_H__227A1E09_1B0A_48D3_815B_1FDBE9A41ADC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawALineDoc : public CDocument
{
protected: // create from serialization only
	CDrawALineDoc();
	DECLARE_DYNCREATE(CDrawALineDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawALineDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawALineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawALineDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWALINEDOC_H__227A1E09_1B0A_48D3_815B_1FDBE9A41ADC__INCLUDED_)
