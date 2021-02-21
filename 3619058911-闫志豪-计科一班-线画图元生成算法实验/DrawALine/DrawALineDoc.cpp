// DrawALineDoc.cpp : implementation of the CDrawALineDoc class
//

#include "stdafx.h"
#include "DrawALine.h"

#include "DrawALineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawALineDoc

IMPLEMENT_DYNCREATE(CDrawALineDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawALineDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawALineDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawALineDoc construction/destruction

CDrawALineDoc::CDrawALineDoc()
{
	// TODO: add one-time construction code here

}

CDrawALineDoc::~CDrawALineDoc()
{
}

BOOL CDrawALineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawALineDoc serialization

void CDrawALineDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDrawALineDoc diagnostics

#ifdef _DEBUG
void CDrawALineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawALineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawALineDoc commands
