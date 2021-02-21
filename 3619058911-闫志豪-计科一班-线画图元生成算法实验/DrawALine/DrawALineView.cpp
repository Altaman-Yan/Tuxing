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
	CPen *pPen=pDC->SelectObject(&pen);//设置画笔
    int min=0,max=1000,dist=4;//规定网格的总尺寸和每个小网格的尺寸
	//用网格表示像素
	for(int i=min;i<=max;i=i+dist){
		//绘制竖线
        pDC->MoveTo(i,min);
		pDC->LineTo(i,max);
		//绘制横线
		pDC->MoveTo(min,i);
		pDC->LineTo(max,i);
    }

	//起点为（20，30），终点为（70，100）
	int x0=20;
	int y0=30;
    int x1=70;
	int y1=100;
	//斜率为负时，交换起点和终点的坐标
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
	pPen=pDC->SelectObject(&pen);//DDA算法描绘出来的直线是红色的

	//首先用DDA算法
	int x=x0,y=y0;
	double yi,xi;
	yi=y0;
	xi=x0;
	double m=(double)(y1-y0)/(double)(x1-x0);
	//当斜率小于1时
	if(m<1){
	    for(int j=0;x<=x1;j++){
		   for(int i=0;i<dist;i++){
			  pDC->MoveTo(x*dist+i,y*dist);
			  pDC->LineTo(x*dist+i,y*dist+dist);
		 }
		 y=(int)(yi+m+0.5);//计算下个点的纵坐标并取整
		 x=x+1;//将下个点的横坐标加1
		 yi=yi+m;
	   }
	}else{//当斜率大于1时
		for(int j=0;y<=y1;j++){
	    	for(int i=0;i<dist;i++){
				pDC->MoveTo(x*dist+i,y*dist);
				pDC->LineTo(x*dist+i,y*dist+dist);
		}
		x=(int)(xi+1/m+0.5);;//计算下个点的坐标并取整
		y=y+1;//将下个点的坐标加1
		xi=xi+1/m;
		}
	}
	//接下来用Bresenham算法
	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	pPen=pDC->SelectObject(&pen);//Bresenham算法描绘出来的直线是蓝色的
	xi = x0;
	yi = y0;
	x = x0;
	y = y0;

	//画第一个点
	for(i=0; i<3; i++){
			pDC->MoveTo(x0*dist + i, y0*dist);
			pDC->LineTo(x0*dist + i, y0*dist + dist);
	}
	int a = x1 - x0;//x差值
	int b = y1 - y0;//y差值

	//当斜率小于1时
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
	}else{//斜率大于1
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
