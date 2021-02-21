// DrawALineView.cpp : implementation of the CDrawALineView class
//

#include "stdafx.h"
#include "DrawALine.h"

#include "DrawALineDoc.h"
#include "DrawALineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawALineView

IMPLEMENT_DYNCREATE(CDrawALineView, CView)

BEGIN_MESSAGE_MAP(CDrawALineView, CView)
	//{{AFX_MSG_MAP(CDrawALineView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawALineView construction/destruction

CDrawALineView::CDrawALineView()
{
	// TODO: add construction code here

}

CDrawALineView::~CDrawALineView()
{
}

BOOL CDrawALineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawALineView drawing

void CDrawALineView::OnDraw(CDC* pDC)
{
	CDrawALineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	CPen pen;
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	CPen *pPen=pDC->SelectObject(&pen);//���û���
    int min=0,max=1000,dist=4;//�涨������ܳߴ��ÿ��С����ĳߴ�
	//�������ʾ����
	for(int i=min;i<=max;i=i+dist){
		//��������
        pDC->MoveTo(i,min);
		pDC->LineTo(i,max);
		//���ƺ���
		pDC->MoveTo(min,i);
		pDC->LineTo(max,i);
    }

	//���Ϊ��20��30�����յ�Ϊ��70��100��
	int x0=20;
	int y0=30;
    int x1=70;
	int y1=100;
	//б��Ϊ��ʱ�����������յ������
	if(x1<x0){
		x0=x0+x1;
		x1=x0-x1;
		x0=x0-x1;
		y0=y0+y1;
		y1=y0-y1;
		y0=y0-y1;
	}

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pPen=pDC->SelectObject(&pen);//DDA�㷨��������ֱ���Ǻ�ɫ��

	//������DDA�㷨
	int x=x0,y=y0;
	double yi,xi;
	yi=y0;
	xi=x0;
	double m=(double)(y1-y0)/(double)(x1-x0);
	//��б��С��1ʱ
	if(m<1){
	    for(int j=0;x<=x1;j++){
		   for(int i=0;i<dist;i++){
			  pDC->MoveTo(x*dist+i,y*dist);
			  pDC->LineTo(x*dist+i,y*dist+dist);
		 }
		 y=(int)(yi+m+0.5);//�����¸���������겢ȡ��
		 x=x+1;//���¸���ĺ������1
		 yi=yi+m;
	   }
	}else{//��б�ʴ���1ʱ
		for(int j=0;y<=y1;j++){
	    	for(int i=0;i<dist;i++){
				pDC->MoveTo(x*dist+i,y*dist);
				pDC->LineTo(x*dist+i,y*dist+dist);
		}
		x=(int)(xi+1/m+0.5);;//�����¸�������겢ȡ��
		y=y+1;//���¸���������1
		xi=xi+1/m;
		}
	}
	//��������Bresenham�㷨
	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	pPen=pDC->SelectObject(&pen);//Bresenham�㷨��������ֱ������ɫ��
	xi = x0;
	yi = y0;
	x = x0;
	y = y0;

	//����һ����
	for(i=0; i<3; i++){
			pDC->MoveTo(x0*dist + i, y0*dist);
			pDC->LineTo(x0*dist + i, y0*dist + dist);
	}
	int a = x1 - x0;//x��ֵ
	int b = y1 - y0;//y��ֵ

	//��б��С��1ʱ
	if((double)b / (double) a < 1){
		int c = 2*b;
		int d = c - 2*a;
		int p = c - a;
		
		for(i=0; i<a; i++){
			if(p > 0)
				y++;
			x++;
			for(int j=0; j<dist; j++){
				pDC->MoveTo(x*dist + j, y*dist);
				pDC->LineTo(x*dist + j, y*dist + dist);
			}
			if(y - yi == 1)
				p += d;//dlower>dupper
			else
				p += c;//dupper>dlower
			yi = y;
		}	
	}else{//б�ʴ���1
		int c = 2*a;
		int d = c - 2*b;
		int p = c - b;

		for(i=0; i<b; i++){
			if(p > 0)
				x++;
			y++;
			for(int j=0; j<dist; j++){
				pDC->MoveTo(x*dist + j, y*dist);
				pDC->LineTo(x*dist + j, y*dist + dist);
			}
			if(x - xi > 0)
				p += d;//dlower>dupper
			else
				p += c;//dlower<dupper

			xi = x;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDrawALineView printing

BOOL CDrawALineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawALineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawALineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawALineView diagnostics

#ifdef _DEBUG
void CDrawALineView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawALineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawALineDoc* CDrawALineView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawALineDoc)));
	return (CDrawALineDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawALineView message handlers
