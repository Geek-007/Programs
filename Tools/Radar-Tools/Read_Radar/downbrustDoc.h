// downbrustDoc.h : interface of the CDownbrustDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include <malloc.h>
#include "datahead.h"
#include <vector>

#if !defined(AFX_DOWNBRUSTDOC_H__02017A5C_62C8_45A3_A4D8_31BC14009B18__INCLUDED_)
#define AFX_DOWNBRUSTDOC_H__02017A5C_62C8_45A3_A4D8_31BC14009B18__INCLUDED_



///窗口参数
//	********************************************/
#define pi 3.1415926
#define R 300
#define D 2*R
#define X0 300
#define Y0 300
#define x_topleft		0
#define y_topleft		0
#define y_rightbottom	600
#define x_rightbottom	1000
#define y_size			600
#define x_size			1000
#define xianshijuli  2 //改变最大显示距离

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CDownbrustDoc : public CDocument
{
protected: // create from serialization only
	CDownbrustDoc();
	DECLARE_DYNCREATE(CDownbrustDoc)

// Attributes
public:
	float RData[MaxCuts][MaxRads][RGates];
	//	RDATA s_Rdata;
	float VData[MaxCuts][MaxRads][VGates];
	float WData[MaxCuts][MaxRads][WGates];
	float RDatah[MaxRads][RGates];
	float Elevation[MaxCuts];
	float AZithm[MaxCuts][MaxRads];
	/*	int n_AZ[MaxCuts];*/
	int NumValidCuts;
	BOOL m_bDataLoad;
	int iPointID;
	int ZBinNumber[MaxCuts];
	float ZBinWidth[MaxCuts];
	int VBinNumber[MaxCuts];
	int ElIndex,AzIndex,BnIndex;
	CString addressStr;//用于获取文件路径
	CString lpszFileName;//用于获取文件名
	_tagRDABaseDataHead* pOneRadial;
	bool shibie;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownbrustDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	double Azimuth(int x, int y);
	int Bin_SA(int x, int y);
	bool Readdata_mestar();
	float DecodeSpw(unsigned char code);
	float DecodeVel(unsigned char code, short ResType);
	float DecodeRef(unsigned char code);
	virtual ~CDownbrustDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDownbrustDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNBRUSTDOC_H__02017A5C_62C8_45A3_A4D8_31BC14009B18__INCLUDED_)
