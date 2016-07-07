// BmpProView.cpp : implementation of the CBmpProView class
//

#include "stdafx.h"
#include "BmpPro.h"
//#include "DoSwap.h"
#include "Mydebug.h"
#include "Dialog.h"

#include "InvalidClick.h"
#include "DialogQuit.h"              
#include "BmpProDoc.h"
#include "BmpProView.h"
#include "Picture.h"
#include<stack>
#include<vector>

//#define int loc_x = 37;
//#define int loc_y = 32;

//#define int up =    1;
//#define int right = 2;
//#define int down =  3;
//#define int left =  4;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpProView

IMPLEMENT_DYNCREATE(CBmpProView, CView)

BEGIN_MESSAGE_MAP(CBmpProView, CView)
	//{{AFX_MSG_MAP(CBmpProView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CANCELMODE()
	ON_COMMAND(ID_PLAYBEJEWELED, OnPlaybejeweled)
	ON_UPDATE_COMMAND_UI(ID_PLAYBEJEWELED, OnUpdatePlaybejeweled)
	ON_COMMAND(ID_EDITMODE_CRYSTALGEM, OnEditmodeCrystalgem)
	ON_UPDATE_COMMAND_UI(ID_EDITMODE_CRYSTALGEM, OnUpdateEditmodeCrystalgem)
	ON_COMMAND(ID_RED_RUBY_GEM, OnRedRubyGem)
	ON_UPDATE_COMMAND_UI(ID_RED_RUBY_GEM, OnUpdateRedRubyGem)
	ON_COMMAND(ID_PlayEditMode, OnPlayEditMode)
	ON_UPDATE_COMMAND_UI(ID_PlayEditMode, OnUpdatePlayEditMode)
	ON_COMMAND(ID_PURPLEGEM, OnPurplegem)
	ON_UPDATE_COMMAND_UI(ID_PURPLEGEM, OnUpdatePurplegem)
	ON_COMMAND(ID_GREENGEM, OnGreengem)
	ON_UPDATE_COMMAND_UI(ID_GREENGEM, OnUpdateGreengem)
	ON_COMMAND(ID_WHITEPEARL, OnWhitepearl)
	ON_UPDATE_COMMAND_UI(ID_WHITEPEARL, OnUpdateWhitepearl)
	ON_COMMAND(ID_YELLOWGEM, OnYellowgem)
	ON_UPDATE_COMMAND_UI(ID_YELLOWGEM, OnUpdateYellowgem)
	ON_COMMAND(ID_ORANGEGEM, OnOrangegem)
	ON_UPDATE_COMMAND_UI(ID_ORANGEGEM, OnUpdateOrangegem)
	ON_COMMAND(ID_BLUEDIAMOND, OnBluediamond)
	ON_UPDATE_COMMAND_UI(ID_BLUEDIAMOND, OnUpdateBluediamond)
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_NEWGAME, OnFileNewgame)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEWGAME, OnUpdateFileNewgame)
	ON_COMMAND(ID_FILE_QUITGAME, OnFileQuitgame)
	ON_UPDATE_COMMAND_UI(ID_FILE_QUITGAME, OnUpdateFileQuitgame)
	ON_COMMAND(ID_SQUARES, OnSquares)
	ON_UPDATE_COMMAND_UI(ID_SQUARES, OnUpdateSquares)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpProView construction/destruction

CBmpProView::CBmpProView()
{
  GAMEMODE = 100;
  ONFILE = -1;
  QUITGAME = -2; 
}

CBmpProView::~CBmpProView()
{
}

BOOL CBmpProView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBmpProView drawing

void CBmpProView::OnDraw(CDC* pDC)
{
	CBmpProDoc* pDoc = GetDocument();
	// check to see if the document is null or has a memory leak
	ASSERT_VALID(pDoc);
	     
	CClientDC dc(this);
  
	 
              

	static int i = 0;
  
    CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
        
    CBmpProDoc * doc = GetDocument();
  
    CBitmap * memory_bitmap = dcMem.SelectObject(pDoc->board->background->bitmap);
    // deselect pointer 
   

    dc.BitBlt(0,0,800,800,&dcMem,0,0,SRCCOPY);
    dcMem.SelectObject(memory_bitmap);

 ///Loads in the bitmap that contains the score 

CBitmap * old = dcMem.SelectObject(pDoc->board->scoreboard->score_bitmap);
   
   
   dc.BitBlt(362,43,400,600,&dcMem,0,0,SRCCOPY);

   dcMem.SelectObject(old);

   doc->board->scoreboard->Draw(&dc);

  

// }
	
  //////////End Load the bitmap 

	TRACE("CALLING THE VIEW \n");
   
	Display(pDC);   

}

/////////////////////////////////////////////////////////////////////////////
// CBmpProView diagnostics

#ifdef _DEBUG
void CBmpProView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpProDoc* CBmpProView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpProDoc)));
	return (CBmpProDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBmpProView message handlers

void CBmpProView::OnInitialUpdate() 
{
//	CScrollView::OnInitialUpdate();

//	SetScrollSizes(MM_TEXT,CSIZE(1280,1024));

  //use scroll class too here
DialogQuit quit;



}

void CBmpProView::Display(CDC * pDC)
{
 
   CBmpProDoc * doc = GetDocument();
   int loc_x = 37;
   int loc_y = 32;
   int i = 0;
   int c = 0;
   int r = 0;
   int flag = 1;
   
   CClientDC screen(this);
   
   CDC memoryDC;       
   memoryDC.CreateCompatibleDC(&screen);

 

   TRACE("IS there a call back to display\n");
   
  // for ( int c = 0; c < 8; c++)
   //{
    while( i < 64)
    {
    // for ( int r = 0; r < 8; r++)
	 //{
       CBitmap * ptr = memoryDC.SelectObject(doc->board->grid[c][r]->bitmap);
	   COLORREF clrTransparent = memoryDC.GetPixel(0,0);
	 //
       //void SetJewelLocation();
	   CRect rect;
	   POINT top_base;
	   POINT bottom_base;
	  
	   top_base.x = loc_x;
	   top_base.y = loc_y;
       
	   bottom_base.x = loc_x + 35;
	   bottom_base.y = loc_y + 32;
       
	   rect.SetRect(top_base,bottom_base);
     
       doc->board->grid[c][r]->setBound(rect);
	 
	 // //break this up into another function 

       TransparentBlt(	pDC->GetSafeHdc() , loc_x, loc_y, 30, 30, 
			memoryDC.GetSafeHdc(), 0, 0, 35, 33,clrTransparent);

       memoryDC.SelectObject(ptr);

	  if(r == 7)
	  flag = 0;
	 
	  if(flag == 1)
	  {
	    loc_x += 36;
        r++;
	  }
   
      if(flag == 0)
	  {
        loc_x = 36;
	    loc_y += 34;
        r=0;
	    c++;
        flag = 1;
	  }

        i++;
	
	}
	
   
} // 36 lines

void CBmpProView::OnLButtonDown(UINT nFlags, CPoint point) 
{	
	CBmpProDoc * doc = GetDocument();

  if(GAMEMODE==100)
  {
    
    Dialog dialog;
    InvalidClick invalid_player_click;
	CClientDC dc(this);
    
	BOOL found = 0;

    TRACE("What is the cursor %d \n",doc->board->cursorx);

    if( (doc->board->cursorx->click) == 0)
	{ 
       
	   found = doc->board->isValidPoint(point);
	   if(found==1)
	   { 
		 
         // I had new Cursor here but it exist even if its null
	     doc->board->cursorx->setCursor(point);
	   //  doc->board->cursorx->click++;
         //display cursor function here
          
		 TRACE("What is the cursor click %d \n",doc->board->cursorx->click);


         //check region by point if true get base point
         Jewel * ptr = doc->board->LookupJewel(point);
		 if(ptr != 0)
		 { doc->board->cursorx->basepoint = ptr->region.TopLeft();
		 
		   doc->board->cursorx->Draw(&dc);
		 }
         
		 if(ptr == NULL)
	     invalid_player_click.DoModal();  //error if the user click location is 
		                                 //located at the base point e.g.
		                                // can't determine what jewel to select

	   }
	   //draw the cursor so that it 
	   //will be displayed correctly by the point
	}// if the is the first left click

   else if(doc->board->cursorx->click == 1 )
   {
      // click to see if the point 
      doc->board->cursorx->click = 0;
	  
      // continue processing  if the point is found int the bound
       
	     Jewel * ptr = doc->board->LookupJewel(point);

		

		   doc->board->cursorx->second_click = point; 
		 
	       TRACE("CANT WE PROCESS THE SECOND CLICK \n");

	       ProcessSecondUserClick(doc->board->cursorx);


		 if( ptr == NULL)
		 {
           invalid_player_click.DoModal();  //error if the user click location is   
		   doc->UpdateAllViews(NULL);
		 }
   }  
  }

  else if(GAMEMODE == -100 )
  {
      //change the settings()

  	  //change jewel
         
      doc->board->cursorx->setCursor(point);
   
	  ChangeJewel(JewelType);       
      
	  
  }

   TRACE("END OF THE FUNCTION LEFT BUTTON DOWN \n");
} //line lines of code in this functon to edit 

// function : ProcessSecondUserClick 
// will determine if there is a match made by adjacent jewels 
// will will also remove the match jewels from the board 
// and replace the empty jewels with valid jewels in the empty 
// spots from the previous match
// function will also calculate the score from the matches made on the board 

bool CBmpProView::ProcessSecondUserClick(cursor * myCursor )
{

    
	
	CClientDC dc(this);
	std::vector<Jewel *> adjacent_jewels;

	Dialog dialog;
    //InvalidClick invalid_player_click;
	BOOL found = 0;
    bool isadjacentbyRow = 0;
    bool isadjacentbyCol = 0;
    bool found_adjacent = 0;
    int total = 0;

    TRACE("ProcessingSecondUserClick \n");


	//check to see if the second point is valid
    CBmpProDoc * doc = GetDocument();

	found = doc->board->isValidPoint(myCursor->second_click);
	if(found==1)
	{ 

         TRACE("IS the second user click by row \n");

         adjacent_jewels = doc->board->isAdjacentROW(doc->board->cursorx,myCursor->second_click);
	     
		 if(adjacent_jewels.size() == 2)
         isadjacentbyRow = ProcessbyAdjacentRow(adjacent_jewels);

		 found_adjacent = isadjacentbyRow;

	}
    
	if(isadjacentbyRow == 0 && found == 1 )
	{
	    
		
	      adjacent_jewels = doc->board->isAdjacentCOLUMN(doc->board->cursorx,myCursor->second_click);
      
         if(adjacent_jewels.size() == 2)
         {
           isadjacentbyCol = ProcessbyAdjacentRow(adjacent_jewels);
		   found_adjacent = isadjacentbyCol;
	
		 }

	 }
    
	return found_adjacent == 1;

}  ///17 lines 


bool CBmpProView::ProcessbyAdjacentRow(std::vector<Jewel *> adjacent_jewels)
{
  bool found = 0;
  CClientDC dc(this);
  int size = 0;

  // click to see if the point is adjacent
   CBmpProDoc * doc = GetDocument();
   
  //adjacent_jewels = doc->board->isAdjacentROW(doc->board->cursorx,doc->board->cursorx->second_click);

  //further process the jewels if they are adjacent_by_row 

  if(adjacent_jewels.size()==2)  //means the container has two adjacent jewels 
  {  
		   
	    found = DOSWAP(adjacent_jewels);  // returns the turn if a match is found 
		                                 // function will remove the jewels 
		                                // and will rewill replace it with new jewels 
		   
		   int total = doc->board->GetMoreMatches(size);
           TRACE("What is the size from GetMoreMatches %d \n",total);

		   if(found)
		   { 
			  // for(int count = 0; count< doc->board->scoreboard->current_score; count++)
			  // {
    
                  SetTimer(IDB_UPDATESCORE,800,NULL);
 
			   //} //or use a while statement here 

			  //doc->board->scoreboard->Draw(&dc);	  
		   
		   }	
  }

   return found == 1;
}

bool CBmpProView::ProcessbyAdjacentCol(std::vector<Jewel *> adjacent_jewels)
{
  bool found = 0;
  CClientDC dc(this);
  int total = 0;
  int size = 0;
  InvalidClick invalid_player_click;

  CBmpProDoc * doc = GetDocument();

  // click to see if the point is adjacent
	    
  adjacent_jewels = doc->board->isAdjacentROW(doc->board->cursorx,doc->board->cursorx->second_click);

  //further process the jewels if they are adjacent_by_row 
  
  if(adjacent_jewels.size()==2)  //means the container has two adjacent jewels 
  {  
		   
	 found = DOSWAP(adjacent_jewels);  // returns the turn if a match is found 
		                                 // function will remove the jewels 
		                                // and will rewill replace it with new jewels 
		   
	int total = doc->board->GetMoreMatches(size);
    TRACE("What is the size from GetMoreMatches %d \n",total);

	if(found)
	{   
		//while(doc->board->scoreboard->count != doc->board->scoreboard->current_score){
		
			SetTimer(IDB_UPDATESCORE,800,NULL);
		

		//}
	    //doc->board->scoreboard->Draw(&dc);	  
		   
	}	
  }
 /* else if( adjacent_jewels.size() < 2 )
  {
       invalid_player_click.DoModal();
       doc->UpdateAllViews(NULL);

  }*/
   return found == 1;
}


void CBmpProView::OnTimer(UINT nIDEvent) 
{
   CBmpProDoc * doc =  GetDocument();
   UINT timer = nIDEvent;
   CClientDC dc(this);

   TRACE("What is the value from the time id %d \n",timer);
  
   if(IDB_UPDATESCREEN == nIDEvent)
   {
   
      doc->UpdateAllViews(NULL);

      KillTimer(IDB_UPDATESCREEN);
   }

   else if(IDB_UPDATESCORE == nIDEvent)
   {
       doc->board->scoreboard->Draw(&dc);
     
       if(doc->board->scoreboard->count == doc->board->scoreboard->current_score)
	   {
          // TRACE("What is the current count %d \n", doc->board->scoreboard->count);
	      KillTimer(IDB_UPDATESCORE);
	   }
	     doc->UpdateAllViews(NULL);
       
   }

   CView::OnTimer(nIDEvent);
}


void CBmpProView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CBmpProView::animation()
{





}


bool CBmpProView::DOSWAP(std::vector<Jewel *> adjacent_jewels)
{

   Jewel * temp_first;  // Jewel * as the first adjacent jewel
   Jewel * temp_second; // Jewel * as the second adjacent jewel
   bool found = 0;
   Dialog dialog;  //pops up if there is an invalid move on 
                  // the board
  
   std::vector<Jewel*>::const_iterator iter;
   std::stack<Jewel *> stack_count;
   std::stack<Index *> stack_index;

   CBmpProDoc * doc = GetDocument();  //get data from the document class

   // iterate over the container of Jewel *
   iter = adjacent_jewels.begin();
   
   temp_first = *iter;
   iter++;
   temp_second = *iter;
   
   //do swap by row or by column 
  
  doc->board->change_index(temp_first->getIndex(),temp_second->getIndex());   

  stack_count = doc->board->GetMatches(); // gets the matches of jewel *
    
  
 if(!stack_count.empty())
 { 
    doc->board->scoreboard->CalculateScore(stack_count);
    
	//set the timer to the interval 1 to 1000 and set the 
	//pointer function to NULL
	
	SetTimer(IDB_UPDATESCREEN,10000,NULL); //      reflects the change if there is a match
	
	//if there is a matches on the stack then remove
	//the jewels from the stack and shift existing 
	//jewels down and generate more jewels

    stack_index = doc->board->remove();
            
	TRACE("THERE IS A MATCH from doSwap \n");
	found = 1;
 }//if statement calculates the score if there are a match of jewels on the stack
 else if(stack_count.empty() )
 {
   doc->board->change_index(temp_second->getIndex(), temp_first->getIndex() );
   found = 0;
   dialog.DoModal();
   doc->UpdateAllViews(NULL);

 } //else if statment will swap back the jewels if they are not adjacent

 //check to see if there is more  with the GetMatches 

  return found == 1;

} // 23 lines 


/*
void CAShapeView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CAShapeDoc* pDoc = GetDocument();
	vector<MyPicture*>& v = pDoc->allShape;

	vector<MyPicture*>::reverse_iterator rb = v.rbegin();
	vector<MyPicture*>::reverse_iterator re = v.rend();

	while (rb != re){
		if ((*rb)->isWithin(point)){
			if( pDoc->aniShape.empty()){
				SetTimer(1, 10, NULL);
			}

			pDoc->aniShape.push_back(*rb);
			break;
		}
		rb++;
	}
	
	CView::OnRButtonDown(nFlags, point);
}

void CAShapeView::OnTimer(UINT nIDEvent) 
{
	CAShapeDoc* pDoc = GetDocument();

	vector<MyPicture*>::iterator b = pDoc->aniShape.begin();
	vector<MyPicture*>::iterator e = pDoc->aniShape.end();

	while (b != e){
		if(!(*b)->animate()){
			pDoc->aniShape.erase(b);
		}

		b++;
	}

	if (pDoc->aniShape.empty())
		KillTimer(1);

	CView::OnTimer(nIDEvent);
}


BOOL MyCircle::animate()
{
	loc.y = loc.y++;
	
	if (loc.y > 500)
		return FALSE;
	else 
		return TRUE;
}
*/

void CBmpProView::OnPlaybejeweled() 
{  
   CBmpProDoc * doc = GetDocument();
   
   if(GAMEMODE == 100)
   doc->UpdateAllViews(NULL);
    
   doc->board->cursorx->click = 0;

   GAMEMODE = 100;
  
    
}

void CBmpProView::OnUpdatePlaybejeweled(CCmdUI* pCmdUI) 
{   
  
	pCmdUI->SetCheck(GAMEMODE == 100);

}

/*void CBmpProView::OnEditmodeCrystaldiamond() 
{
//	JewelType = 1;
}

void CBmpProView::OnUpdateEditmodeCrystaldiamond(CCmdUI* pCmdUI) 
{

//	pCmdUI->SetCheck(JewelType == 1);
}*/

void CBmpProView::OnEditmodeCrystalgem() 
{
    
}

void CBmpProView::OnUpdateEditmodeCrystalgem(CCmdUI* pCmdUI) 
{

}

void CBmpProView::OnRedRubyGem() 
{
    JewelType = 2;	
}

void CBmpProView::OnUpdateRedRubyGem(CCmdUI* pCmdUI) 
{
  pCmdUI->SetCheck(JewelType==2);

}



void CBmpProView::OnPlayEditMode() 
{ 
   UINT value = 0;
   
   

  if(GAMEMODE==100)
  { CString str("Are your sure you want to Exit ''Play Bejeweled'' ");
    value = MessageBox(_T("Are your sure you want to Exit ''Play Bejeweled'' "),
		     _T("Select Chooses"), IDYES || IDNO || IDCANCEL );

	if(value == 1)  // aka IDYES
	{
       GAMEMODE = -100;
	   
	}     
  }
	
}

void CBmpProView::OnUpdatePlayEditMode(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GAMEMODE == -100);

}

void CBmpProView::OnPurplegem() 
{
	JewelType = 7;
}

void CBmpProView::OnUpdatePurplegem(CCmdUI* pCmdUI) 
{
   pCmdUI->SetCheck(JewelType == 7);
	//this is not purple but orange
}

void CBmpProView::OnGreengem() 
{
	JewelType = 1;
}

void CBmpProView::OnUpdateGreengem(CCmdUI* pCmdUI) 
{
    	
   	pCmdUI->SetCheck(JewelType == 1);

}


void CBmpProView::OnWhitepearl() 
{
	JewelType = 4;
}

void CBmpProView::OnUpdateWhitepearl(CCmdUI* pCmdUI) 
{

	pCmdUI->SetCheck(JewelType == 4);

}

void CBmpProView::OnYellowgem() 
{
  JewelType = 3;
	
}

void CBmpProView::OnUpdateYellowgem(CCmdUI* pCmdUI) 
{

	pCmdUI->SetCheck(JewelType == 3);
	
}

void CBmpProView::OnOrangegem() 
{
  JewelType = 5;
	
}


void CBmpProView::OnUpdateOrangegem(CCmdUI* pCmdUI) 
{
	
	pCmdUI->SetCheck(JewelType==5);
}

void CBmpProView::OnBluediamond() 
{
   JewelType = 6;	
}

void CBmpProView::OnUpdateBluediamond(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(JewelType == 6);
}



void CBmpProView::OnFileNewgame() 
{
   ONFILE = 200;	
   CBmpProDoc * doc = GetDocument();
   doc->OnNewDocument();

}

void CBmpProView::OnUpdateFileNewgame(CCmdUI* pCmdUI) 
{  
   pCmdUI->SetCheck(ONFILE == 200);
}




void CBmpProView::ChangeJewel(int type)
{
   CBmpProDoc * doc = GetDocument();
   BOOL found = 0;	
   //check it the point is valid
	//then change with rect
   
   CPoint point = doc->board->cursorx->getSavePoint();

   found = doc->board->isValidPoint(point);
  
   if(found )
   {
        Jewel * ptr = doc->board->LookupJewel(point);
        
        if(ptr->JewelType() != type && ptr != NULL)
		{

		   Index * i = ptr->getIndex(); 
		 
           int c = i->col;

           int r = i->row;

	       Jewel * new_jewel = new Jewel(type);
          
		   Index * index = new Index(r,c);
          
		   new_jewel->setIndex(index);

		  //might need the bound here 

		   doc->board->grid[r][c] = new_jewel;
		  
		   doc->UpdateAllViews(NULL);

		}     
   }

   else if (!found)//|| ptr == NULL)
   {

       TRACE("The jewel can not be changed \n");

   }
	   
         	  
  
}




void CBmpProView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
   TRACE("What is the size of the window %d %d \n",cx, cy);	

     cx = 100;
	 cy = 9;


}

void CBmpProView::OnFileQuitgame() 
{
   QUITGAME = 1000; 	
    
   PostMessage(ID_APP_EXIT,0,0);
}

void CBmpProView::OnUpdateFileQuitgame(CCmdUI* pCmdUI) 
{
  pCmdUI->SetCheck(QUITGAME==1000);
}


bool CBmpProView::DeadLock()
{
 
  return true;
}


int CBmpProView::Direction(Jewel * jewel)
{
   
  std::vector<int> valid_direction;
  Index * index = jewel->getIndex();
  int col =  index->col; 
  int row =  index->row;
 
  
return 0;

}

void CBmpProView::OnSquares() 
{
	// TODO: Add your command handler code here

}

void CBmpProView::OnUpdateSquares(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
