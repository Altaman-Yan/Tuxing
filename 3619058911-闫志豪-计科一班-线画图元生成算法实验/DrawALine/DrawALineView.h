// DrawALineView.h : interface of the CDrawALineView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWALINEVIEW_H__6BDADE7A_9B40_4786_A65C_EC16D9CD5CA2__INCLUDED_)
#define AFX_DRAWALINEVIEW_H__6BDADE7A_9B40_4786_A65C_EC16D9CD5CA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawALineView : public CView
{
protected: // create from serialization only
	CDrawALineView();
	DECLARE_DYNCREATE(CDrawALineView)

// Attributes
public:
	CDrawALineDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawALineView)
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
	virtual ~CDrawALineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawALineView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawALineView.cpp
inline CDrawALineDoc* CDrawALineView::GetDocument()
   { return (CDrawALineDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWALINEVIEW_H__6BDADE7A_9B40_4786_A65C_EC16D9CD5CA2__INCLUDED_)
