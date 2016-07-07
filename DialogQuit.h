#if !defined(AFX_DIALOGQUIT_H__95DA50AA_474C_439B_BD2A_31F94E71D43A__INCLUDED_)
#define AFX_DIALOGQUIT_H__95DA50AA_474C_439B_BD2A_31F94E71D43A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogQuit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DialogQuit dialog

class DialogQuit : public CDialog
{
// Construction
public:
	DialogQuit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DialogQuit)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DialogQuit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DialogQuit)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGQUIT_H__95DA50AA_474C_439B_BD2A_31F94E71D43A__INCLUDED_)
