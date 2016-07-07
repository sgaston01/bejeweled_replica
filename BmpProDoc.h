// BmpProDoc.h : interface of the CBmpProDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include "Picture.h"
#include<stack>


#if !defined(AFX_BMPPRODOC_H__26F47DE1_9265_4E19_8793_3A59B28793CE__INCLUDED_)
#define AFX_BMPPRODOC_H__26F47DE1_9265_4E19_8793_3A59B28793CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <wingdi.h>


class CBmpProDoc : public CDocument
{
protected: // create from serialization only
	CBmpProDoc();
	DECLARE_DYNCREATE(CBmpProDoc)
    
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpProDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	int removal(std::stack<Jewel *> &);
	Gameboard *board;
    bool Isvalid();
 
	bool rowIsValid();
	bool colIsValid();
    void change_middle(std::vector<Jewel *> matches);

	void deleteBoard();
	UINT m_height;
	UINT m_width;
	CBitmap m_bitmap;
	virtual ~CBmpProDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpProDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPPRODOC_H__26F47DE1_9265_4E19_8793_3A59B28793CE__INCLUDED_)
