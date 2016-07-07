// DialogQuit.cpp : implementation file
//

#include "stdafx.h"
#include "BmpPro.h"
#include "DialogQuit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogQuit dialog


DialogQuit::DialogQuit(CWnd* pParent /*=NULL*/)
	: CDialog(DialogQuit::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogQuit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DialogQuit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogQuit)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogQuit, CDialog)
	//{{AFX_MSG_MAP(DialogQuit)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogQuit message handlers
