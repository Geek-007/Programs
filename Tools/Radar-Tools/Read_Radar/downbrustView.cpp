// downbrustView.cpp : implementation of the CDownbrustView class
//

#include "stdafx.h"
#include "downbrust.h"

#include "downbrustDoc.h"
#include "downbrustView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
bool a=false,b=false,c=false;
int e1;

// CDownbrustView

IMPLEMENT_DYNCREATE(CDownbrustView, CView)

BEGIN_MESSAGE_MAP(CDownbrustView, CView)
	//{{AFX_MSG_MAP(CDownbrustView)
	ON_COMMAND(IDM_SHOWREF, OnShowref)
	ON_COMMAND(IDM_SHOWPK, OnShowpk)
	ON_COMMAND(IDM_SHOWVEL, OnShowvel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownbrustView construction/destruction

CDownbrustView::CDownbrustView()
{
	// TODO: add construction code here

}

CDownbrustView::~CDownbrustView()
{
}

BOOL CDownbrustView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
/////////////////////////////////////////////////////////////////////////////
//强度图色标 14个色标  RGB配色
struct Ref_Colortab
{int r,g,b;
}colorref[15]={	
	
	{0,0,0},          //-5~0
	{0,230,255},        //0~5
	{0,150,255},        //5~10
	{0,0,255},      //10~15
	{0,255,0},         //15~20
	{0,200,0},          //20~25
	{0,128,0},      //25~30
	{255,255,0},        //30~35
	{220,180,0},        //35~40
	{210,140,125},        //40~45
	{255,0,0},      //45~50
	{170,0,0},      //50~55
	{100,0,0},      //55~60
	{255,0,255},      //60~65
	{255,180,255},        //>65
	}; 
//速度图色标
struct Vel_Colortab
{int r,g,b;
}colorvel[16]={	
	{0,0,162},
	{0,107,255},
	{0,224,239},
	{150,200,255},
	{180,255,180},
	{0,220,0},
	{0,150,50},
	{200,200,200},
	{200,50,50},
	{255,100,100},
	{255,180,180},
	{238,255,170},
	{240,240,0},
	{196,196,0},
	{138,138,0},
	{0,0,0}
};
//谱宽图色标
struct W_Colortab
{int r,g,b;
}colorW[17]={	
	{110,248,255},
	{0,255,255},
	{0,107,253},
	{0,0,162},
	{115,255,138},
	{0,255,0},
	{0,150,50},
	{255,180,0},
	{255,255,0},
	{196,166,0},
	{255,100,100},
	{255,0,0},
	{128,0,0},
	{250,200,250},
	{200,100,155},
	{150,0,180},
	{0,0,0}
};
/////////////////////////////////////////////////////////////////////////////


// CDownbrustView drawing

void CDownbrustView::OnDraw(CDC* pDC)
{
	CDownbrustDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int rot,az,ColorNum1,ColorNum2,ColorNum3;
	CDC MemDC; //首先定义一个显示设备对象
	CBitmap MemBitmap;   //定义一个位图对象
	MemDC.CreateCompatibleDC(NULL);     //随后建立与屏幕显示兼容的内存显示设备
	MemBitmap.CreateCompatibleBitmap(pDC,x_size,y_size);  //建立一个与屏幕显示兼容的位图		
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);  //将位图选入到内存显示设备中    
	MemDC.FillSolidRect(x_topleft,y_topleft,x_rightbottom,y_rightbottom,RGB(0,0,0));  //背景色,这里我用的是白色作为背景

	//******************开始绘制SA/SB格式数据的反射率 速度 谱宽图**************
	
		if (a==true)
		{
			for (int x=0;x<=2*R;x++)
			{
				for (int y=0;y<=2*R;y++)
				{
					rot=pDoc->Bin_SA(x,y);
					az=int(180*1.0f-pDoc->Azimuth(x,y));
					if (pDoc->shibie==true)
					{
						ColorNum1=Ref_Color_Number(pDoc->RDatah[az][rot]);
						if(rot<=(R/xianshijuli)&&rot!=-1)
						{
							if(pDoc->RData[e1][az][rot]!=-999)
								MemDC.SetPixel(x,y,RGB(colorref[ColorNum1].r,colorref[ColorNum1].g,colorref[ColorNum1].b));		
						}
					}
					else
					{
						ColorNum1=Ref_Color_Number(pDoc->RData[e1][az][rot]);
						if(rot<=(R/xianshijuli)&&rot!=-1)
						{
							if(pDoc->RData[e1][az][rot]!=-999)
								MemDC.SetPixel(x,y,RGB(colorref[ColorNum1].r,colorref[ColorNum1].g,colorref[ColorNum1].b));		
						}
					}
					
					
				}
			}					
		}
		if (b==true)
		{
			for(int x=0;x<=2*R;x++)//画图程序
				for(int y=0;y<=2*R;y++)
				{
					rot=pDoc->Bin_SA(x,y);//距离库
					az=int(180*1.0f-pDoc->Azimuth(x,y));
					ColorNum2=Vel_Color_Number(pDoc->VData[e1][az][rot]);
					if (rot<=(R/xianshijuli)&&rot!=-1)
					{
						if (pDoc->VData[e1][az][rot]!=-999&&pDoc->VData[e1][az][rot]!=999)
							MemDC.SetPixel(CPoint(x,y),RGB(colorvel[ColorNum2].r,colorvel[ColorNum2].g,colorvel[ColorNum2].b));
					}	
				}
		}   
	CBrush *pNewBrush,*pOldBrush;//(下面四个设置)
	MemDC.SelectStockObject(OEM_FIXED_FONT);//选择系统字体
	MemDC.SetTextAlign(TA_BASELINE);//设置文本的对齐方式为：将点与所选字体的基线对齐
	MemDC.SetBkMode(TRANSPARENT);//设置背景模式为不透明
	MemDC.SetTextColor(RGB(255,255,255));//设置文本颜色为白色
	//MemDC.SetTextColor(RGB(0,0,255));//设置文本颜色为黑色

    CString str;
	//反射率色标卡
    if (a==true)
    {
    
		for (int j=1;j<16;j++)
		{
			pNewBrush=new CBrush;
			pNewBrush->CreateSolidBrush(RGB(colorref[15-j].r,colorref[15-j].g,colorref[15-j].b));
			pOldBrush=MemDC.SelectObject(pNewBrush);
			MemDC.Rectangle(D+60,R-15+j*20,D+100,R+5+j*20);//画反射率图标
			delete pNewBrush;
			MemDC.SelectObject(pOldBrush);
			
		}

		MemDC.TextOut(D+100,R+10+1*20,"65");
		MemDC.TextOut(D+100,R+10+2*20,"60");
		MemDC.TextOut(D+100,R+10+3*20,"55");
		MemDC.TextOut(D+100,R+10+4*20,"50");
		MemDC.TextOut(D+100,R+10+5*20,"45");
		MemDC.TextOut(D+100,R+10+6*20,"40");	
		MemDC.TextOut(D+100,R+10+7*20,"35");		
		MemDC.TextOut(D+100,R+10+8*20,"30");
		MemDC.TextOut(D+100,R+10+9*20,"25");
		MemDC.TextOut(D+100,R+10+10*20,"20");
		MemDC.TextOut(D+100,R+10+11*20,"15");
		MemDC.TextOut(D+100,R+10+12*20,"10");
		MemDC.TextOut(D+100,R+10+13*20,"5");
		MemDC.TextOut(D+100,R+10+14*20,"0");
		MemDC.TextOut(D+10,R-25,"反射率DBZ");  

	}
	//速度色标卡
	if(b==true)
		{	
			for (int j=1;j<16;j++)
			{
				pNewBrush=new CBrush;
				pNewBrush->CreateSolidBrush(RGB(colorvel[15-j].r,colorvel[15-j].g,colorvel[15-j].b));
				pOldBrush=MemDC.SelectObject(pNewBrush);
				MemDC.Rectangle(D+60,R+5+j*20,D+100,R+25+j*20);//画反射率图标
				//			str.Format("%2d",(15-j)*5-5); 
				//			MemDC.TextOut(D+50,R+10+j*20,str);//输出色标值
				delete pNewBrush;
				MemDC.SelectObject(pOldBrush);
				
			}
			MemDC.SetTextColor(255);
			
			MemDC.TextOut(D+100,R+10+1*20,"40");
			MemDC.TextOut(D+100,R+10+2*20,"32");
			MemDC.TextOut(D+100,R+10+3*20,"24");
			MemDC.TextOut(D+100,R+10+4*20,"18");
			MemDC.TextOut(D+100,R+10+5*20,"12");
			MemDC.TextOut(D+100,R+10+6*20," 8");	
			MemDC.TextOut(D+100,R+10+7*20," 4");		
			MemDC.TextOut(D+100,R+10+8*20," 2");
			MemDC.TextOut(D+100,R+10+9*20,"-2");
			MemDC.TextOut(D+100,R+10+10*20,"-4");
			MemDC.TextOut(D+100,R+10+11*20,"-8");
			MemDC.TextOut(D+100,R+10+12*20,"-12");
			MemDC.TextOut(D+100,R+10+13*20,"-18");
			MemDC.TextOut(D+100,R+10+14*20,"-24");
			MemDC.TextOut(D+100,R+10+15*20,"-32");
			MemDC.TextOut(D+100,R+10+16*20,"-40");
			MemDC.TextOut(D+10,R+5,"径向速度m/s");
	}
	if (c==true)
	{
		for (int j=1;j<17;j++)
		{
			pNewBrush=new CBrush;
			pNewBrush->CreateSolidBrush(RGB(colorW[16-j].r,colorW[16-j].g,colorW[16-j].b));
			pOldBrush=MemDC.SelectObject(pNewBrush);
			MemDC.Rectangle(D+60,R-15+j*20,D+100,R+5+j*20);//画反射率图标
			//			str.Format("%2d",(15-j)*5-5); 
			//			MemDC.TextOut(D+50,R+10+j*20,str);//输出色标值
			delete pNewBrush;
			MemDC.SelectObject(pOldBrush);
			
		}
		
		MemDC.TextOut(D+100,R+1*20,"14.0");
		MemDC.TextOut(D+100,R+2*20,"13.0");
		MemDC.TextOut(D+100,R+3*20,"12.0");
		MemDC.TextOut(D+100,R+4*20,"11.0");
		MemDC.TextOut(D+100,R+5*20,"10.0");
		MemDC.TextOut(D+100,R+6*20,"9.0");	
		MemDC.TextOut(D+100,R+7*20,"8.0");		
		MemDC.TextOut(D+100,R+8*20,"7.0");
		MemDC.TextOut(D+100,R+9*20,"6.0");
		MemDC.TextOut(D+100,R+10*20,"5.0");
		MemDC.TextOut(D+100,R+11*20,"4.0");
		MemDC.TextOut(D+100,R+12*20,"3.0");
		MemDC.TextOut(D+100,R+13*20,"2.0");
		MemDC.TextOut(D+100,R+14*20,"1.0");
		MemDC.TextOut(D+100,R+15*20,"0.5");
		MemDC.TextOut(D+100,R+16*20,"0.0");
		MemDC.TextOut(D+10,R-25,"谱宽m/s");
	}
		CPen* pOldPen;
		CPen NewPen;
		NewPen.CreatePen(PS_SOLID,1,RGB(255,255,255));
		pOldPen=MemDC.SelectObject(&NewPen);
		MemDC.MoveTo(R,0);
		MemDC.LineTo(R,D);
		MemDC.MoveTo(0,R);
		MemDC.LineTo(D,R);
		MemDC.MoveTo(R-R*0.707,R-R*0.707);
		MemDC.LineTo(R+R*0.707,R+R*0.707);
		MemDC.MoveTo(R+R*0.707,R-R*0.707);
		MemDC.LineTo(R-R*0.707,R+R*0.707);
		MemDC.MoveTo(D,0);
		MemDC.LineTo(D,D);
		
		for(int r=R;r>=R/5;r=r-R/5)//画距离圈
		{
			MemDC.Arc(R-r,R-r,R+r,R+r,0,0,0,0);
		}
	MemDC.SelectObject(pOldPen);
	pDC->BitBlt(x_topleft,y_topleft,x_size,y_size,&MemDC,0,0,SRCCOPY);
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();  
}

/////////////////////////////////////////////////////////////////////////////
// CDownbrustView printing

BOOL CDownbrustView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDownbrustView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDownbrustView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDownbrustView diagnostics

#ifdef _DEBUG
void CDownbrustView::AssertValid() const
{
	CView::AssertValid();
}

void CDownbrustView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDownbrustDoc* CDownbrustView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDownbrustDoc)));
	return (CDownbrustDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDownbrustView message handlers



void CDownbrustView::OnShowref() 
{
	// TODO: Add your command handler code here
	CDownbrustDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->shibie=false;
	a=true;b=false;c=false;
    Invalidate(false);
}

void CDownbrustView::OnShowpk() 
{
	// TODO: Add your command handler code here
	a=false;b=false;c=true;		 
	
	Invalidate(false);
}

void CDownbrustView::OnShowvel() 
{
	// TODO: Add your command handler code here
	a=false;b=true;c=false;		
    Invalidate(false);
}

int CDownbrustView::Ref_Color_Number(int ref)
{
	int ColorNum;
	if (ref>-5&&ref<=0)		    	ColorNum=0;
	else if (ref>0&&ref<=5)	    	ColorNum=1;
	else if (ref>5&&ref<=10)		ColorNum=2;
	else if (ref>10&&ref<=15)		ColorNum=3;	
	else if (ref>15&&ref<=20)		ColorNum=4;	
	else if (ref>20&&ref<=25)		ColorNum=5;
	else if (ref>25&&ref<=30)		ColorNum=6;
	else if (ref>30&&ref<=35)		ColorNum=7;
	else if (ref>35&&ref<=40)		ColorNum=8;
	else if (ref>40&&ref<=45)		ColorNum=9;
	else if (ref>45&&ref<=50)		ColorNum=10;
	else if (ref>50&&ref<=55)		ColorNum=11;
	else if (ref>55&&ref<=60)		ColorNum=12;
	else if (ref>60&&ref<=65)		ColorNum=13;
	else if (ref>65)				ColorNum=14;
	else 						    ColorNum=0;			
	return ColorNum;
}

int CDownbrustView::Vel_Color_Number(float vel)
{
	int ColorNum;
	if (vel>-40&&vel<=-32)		        ColorNum=0;// 42-36
	else if (vel>-32&&vel<=-24)	        ColorNum=1;//36-30
	else if (vel>-24&&vel<=-18)	        ColorNum=2;//30-24
	else if (vel>-18&&vel<=-12)	        ColorNum=3;//24-18
	else if (vel>-12&&vel<=-8)	        ColorNum=4;//18-12
	else if (vel>-8&&vel<=-4)	        ColorNum=5;//6-12
	else if (vel>-4&&vel<=-2)        	ColorNum=6;//0-6
	else if (vel>-2&&vel<=2)			ColorNum=7;//0
	else if (vel>2&&vel<=4)             ColorNum=8;//
	else if (vel>4&&vel<=8)	            ColorNum=9;
	else if (vel>8&&vel<=12)	        ColorNum=10;
	else if (vel>12&&vel<=18)	        ColorNum=11;
	else if (vel>18&&vel<=24)	        ColorNum=12;
	else if (vel>24&&vel<=32)	        ColorNum=13;
	else if (vel>32&&vel<=40)	        ColorNum=14; 
	else 						        ColorNum=15;
	return(ColorNum);
}

int CDownbrustView::W_Color_Number(int w)
{
	int ColorNum;
	if (w>=0.&&w<=0.5)		    	ColorNum=1;
	else if (w>0.5&&w<=1.0)	    	ColorNum=2;
	else if (w>1.0&&w<=2.0)	    	ColorNum=3;
	else if (w>2.0&&w<=3.0)		    ColorNum=4;	
	else if (w>3.0&&w<=4.0)	     	ColorNum=5;	
	else if (w>4.0&&w<=5.0)		    ColorNum=6;
	else if (w>5.0&&w<=6.0)	    	ColorNum=7;
	else if (w>6.0&&w<=7.0)		    ColorNum=8;
	else if (w>7.0&&w<=8.0)		    ColorNum=9;
	else if (w>8.0&&w<=9.0)	    	ColorNum=10;
	else if (w>9.0&&w<=10.0)		ColorNum=11;
	else if (w>10.0&&w<=11.0)		ColorNum=12;
	else if (w>11.0&&w<=12.0)		ColorNum=13;
	else if (w>12.0&&w<=13.0)		ColorNum=14;
	else if (w>13.0&&w<=14.0)		ColorNum=15;
	else if (w>14)	         	    ColorNum=16;
	else 						    ColorNum=16;			
	return ColorNum;
}




