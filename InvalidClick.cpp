// InvalidClick.cpp : implementation file
//

#include "stdafx.h"
#include "BmpPro.h"
#include "InvalidClick.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InvalidClick dialog


InvalidClick::InvalidClick(CWnd* pParent /*=NULL*/)
	: CDialog(InvalidClick::IDD, pParent)
{
	//{{AFX_DATA_INIT(InvalidClick)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void InvalidClick::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InvalidClick)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InvalidClick, CDialog)
	//{{AFX_MSG_MAP(InvalidClick)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InvalidClick message handlers
