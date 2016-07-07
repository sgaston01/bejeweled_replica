#if !defined(AFX_INVALIDDIALOG_H__6DAAFB2B_758A_4710_A2A6_30907C6A5651__INCLUDED_)
#define AFX_INVALIDDIALOG_H__6DAAFB2B_758A_4710_A2A6_30907C6A5651__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InvalidDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InvalidDialog dialog

class InvalidDialog : public CDialog
{
// Construction
public:
	InvalidDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InvalidDialog)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InvalidDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InvalidDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INVALIDDIALOG_H__6DAAFB2B_758A_4710_A2A6_30907C6A5651__INCLUDED_)
