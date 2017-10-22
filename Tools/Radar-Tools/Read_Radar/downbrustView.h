// downbrustView.h : interface of the CDownbrustView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOWNBRUSTVIEW_H__6AA126B6_E2F0_4911_A37B_FFD8D5C7E96B__INCLUDED_)
#define AFX_DOWNBRUSTVIEW_H__6AA126B6_E2F0_4911_A37B_FFD8D5C7E96B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDownbrustView : public CView
{
protected: // create from serialization only
	CDownbrustView();
	DECLARE_DYNCREATE(CDownbrustView)

// Attributes
public:
	CDownbrustDoc* GetDocument();

// Operations
	
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownbrustView)
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
	int W_Color_Number(int w);
	int Vel_Color_Number(float vel);
	int Ref_Color_Number(int ref);
	virtual ~CDownbrustView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDownbrustView)
	afx_msg void OnShowref();
	afx_msg void OnShowpk();
	afx_msg void OnShowvel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in downbrustView.cpp
inline CDownbrustDoc* CDownbrustView::GetDocument()
   { return (CDownbrustDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNBRUSTVIEW_H__6AA126B6_E2F0_4911_A37B_FFD8D5C7E96B__INCLUDED_)
