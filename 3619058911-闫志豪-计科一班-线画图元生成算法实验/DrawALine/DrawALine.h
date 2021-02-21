// DrawALine.h : main header file for the DRAWALINE application
//

#if !defined(AFX_DRAWALINE_H__DF6D3A45_C10A_42C0_BD08_D6B5F68E56CB__INCLUDED_)
#define AFX_DRAWALINE_H__DF6D3A45_C10A_42C0_BD08_D6B5F68E56CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawALineApp:
// See DrawALine.cpp for the implementation of this class
//

class CDrawALineApp : public CWinApp
{
public:
	CDrawALineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawALineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDrawALineApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWALINE_H__DF6D3A45_C10A_42C0_BD08_D6B5F68E56CB__INCLUDED_)
