#if !defined(AFX_INVALIDCLICK_H__8230020C_6D5B_4373_ADDD_A0F42B2E097D__INCLUDED_)
#define AFX_INVALIDCLICK_H__8230020C_6D5B_4373_ADDD_A0F42B2E097D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InvalidClick.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InvalidClick dialog

class InvalidClick : public CDialog
{
// Construction
public:
	InvalidClick(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InvalidClick)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InvalidClick)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InvalidClick)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INVALIDCLICK_H__8230020C_6D5B_4373_ADDD_A0F42B2E097D__INCLUDED_)
