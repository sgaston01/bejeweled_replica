// BmpProView.h : interface of the CBmpProView class
//
/////////////////////////////////////////////////////////////////////////////
#include "Picture.h"
#include<stack>
#include<vector>


#if !defined(AFX_BMPPROVIEW_H__42D2E9E1_EBBF_41DD_ACB5_A945E39347A7__INCLUDED_)
#define AFX_BMPPROVIEW_H__42D2E9E1_EBBF_41DD_ACB5_A945E39347A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CBmpProView : public CView
{
protected:
//Gameboard * board;


protected: // create from serialization only
	CBmpProView();
	DECLARE_DYNCREATE(CBmpProView)
 
// Attributes
public:
	CBmpProDoc* GetDocument();
    void animation();
	bool DOSWAP(std::vector<Jewel *> adjacent_jewels );
    bool ProcessSecondUserClick(cursor * myCursor );
	bool ProcessbyAdjacentRow(std::vector<Jewel *> adjacent_jewel);
    bool ProcessbyAdjacentCol(std::vector<Jewel *> adjacent_jewel);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpProView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	void ChangeJewel(int type);
	void Display(CDC * pDC);
	bool DeadLock();
	
	virtual ~CBmpProView();
	//void CBmpProView::OnPlaybejeweled() 
    int GAMEMODE;
	int JewelType;
	int ONFILE;
	int QUITGAME;
 ///////////////////////////////  
	
	int direction_of_one;
	int direction_of_two;
	int direction_of_three;
	int direction_of_four;

//////////////////////////////

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
int Direction(Jewel * jewel); //know the direct that can be moved 

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpProView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCancelMode();
	afx_msg void OnPlaybejeweled();
	afx_msg void OnUpdatePlaybejeweled(CCmdUI* pCmdUI);
	afx_msg void OnEditmodeCrystalgem();
	afx_msg void OnUpdateEditmodeCrystalgem(CCmdUI* pCmdUI);
	afx_msg void OnRedRubyGem();
	afx_msg void OnUpdateRedRubyGem(CCmdUI* pCmdUI);
	afx_msg void OnPlayEditMode();
	afx_msg void OnUpdatePlayEditMode(CCmdUI* pCmdUI);
	afx_msg void OnPurplegem();
	afx_msg void OnUpdatePurplegem(CCmdUI* pCmdUI);
	afx_msg void OnGreengem();
	afx_msg void OnUpdateGreengem(CCmdUI* pCmdUI);
	afx_msg void OnWhitepearl();
	afx_msg void OnUpdateWhitepearl(CCmdUI* pCmdUI);
	afx_msg void OnYellowgem();
	afx_msg void OnUpdateYellowgem(CCmdUI* pCmdUI);
	afx_msg void OnOrangegem();
	afx_msg void OnUpdateOrangegem(CCmdUI* pCmdUI);
	afx_msg void OnBluediamond();
	afx_msg void OnUpdateBluediamond(CCmdUI* pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileNewgame();
	afx_msg void OnUpdateFileNewgame(CCmdUI* pCmdUI);
	afx_msg void OnFileQuitgame();
	afx_msg void OnUpdateFileQuitgame(CCmdUI* pCmdUI);
	afx_msg void OnSquares();
	afx_msg void OnUpdateSquares(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BmpProView.cpp
inline CBmpProDoc* CBmpProView::GetDocument()
   { return (CBmpProDoc*)m_pDocument; }
#endif


//need a endline like this one

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPPROVIEW_H__42D2E9E1_EBBF_41DD_ACB5_A945E39347A7__INCLUDED_)
