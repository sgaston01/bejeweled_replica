#if !defined(AFX_MYDEBUG_H__DB196220_17AC_11CD_8666_BD6B9B04AF2F__INCLUDED_)
#define AFX_MYDEBUG_H__DB196220_17AC_11CD_8666_BD6B9B04AF2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mydebug.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Mydebug dialog

class Mydebug : public CDialog
{
// Construction
public:
	Mydebug(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Mydebug)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Mydebug)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Mydebug)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDEBUG_H__DB196220_17AC_11CD_8666_BD6B9B04AF2F__INCLUDED_)
