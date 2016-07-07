// Mydebug.cpp : implementation file
//

#include "stdafx.h"
#include "BmpPro.h"
#include "Mydebug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Mydebug dialog


Mydebug::Mydebug(CWnd* pParent /*=NULL*/)
	: CDialog(Mydebug::IDD, pParent)
{
	//{{AFX_DATA_INIT(Mydebug)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Mydebug::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Mydebug)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Mydebug, CDialog)
	//{{AFX_MSG_MAP(Mydebug)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Mydebug message handlers
