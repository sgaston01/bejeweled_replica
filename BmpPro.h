// BmpPro.h : main header file for the BMPPRO application
//

#if !defined(AFX_BMPPRO_H__5C498BA3_A20C_4480_9298_7A2D3745BD99__INCLUDED_)
#define AFX_BMPPRO_H__5C498BA3_A20C_4480_9298_7A2D3745BD99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmpProApp:
// See BmpPro.cpp for the implementation of this class
//

class CBmpProApp : public CWinApp
{
public:
	CBmpProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBmpProApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPPRO_H__5C498BA3_A20C_4480_9298_7A2D3745BD99__INCLUDED_)
