// downbrust.h : main header file for the DOWNBRUST application
//

#if !defined(AFX_DOWNBRUST_H__81386442_0CA4_4E79_85D0_9E52326986F7__INCLUDED_)
#define AFX_DOWNBRUST_H__81386442_0CA4_4E79_85D0_9E52326986F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownbrustApp:
// See downbrust.cpp for the implementation of this class
//

class CDownbrustApp : public CWinApp
{
public:
	CDownbrustApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownbrustApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDownbrustApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNBRUST_H__81386442_0CA4_4E79_85D0_9E52326986F7__INCLUDED_)
