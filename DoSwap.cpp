// DoSwap.cpp : implementation file
//

#include "stdafx.h"
#include "BmpPro.h"
#include "DoSwap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DoSwap dialog


DoSwap::DoSwap(CWnd* pParent /*=NULL*/)
	: CDialog(DoSwap::IDD, pParent)
{
	//{{AFX_DATA_INIT(DoSwap)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DoSwap::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DoSwap)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DoSwap, CDialog)
	//{{AFX_MSG_MAP(DoSwap)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DoSwap message handlers
