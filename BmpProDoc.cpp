// BmpProDoc.cpp : implementation of the CBmpProDoc class
//

#include "stdafx.h"
#include "BmpPro.h"
#include<stack>
#include<list>

#include "BmpProDoc.h"
//#include "DoSwap.h"
#include<stack>
#include"Picture.h"

#include<ctime>
#include<stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpProDoc

IMPLEMENT_DYNCREATE(CBmpProDoc, CDocument)

BEGIN_MESSAGE_MAP(CBmpProDoc, CDocument)
	//{{AFX_MSG_MAP(CBmpProDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpProDoc construction/destruction

CBmpProDoc::CBmpProDoc()
{
   bool done = 0;

   board = new Gameboard();
   int type;
   CPoint points;
   std::stack<Jewel *> matchesRow;
   std::stack<Jewel *> matchesCol;
   std::list<Jewel *> matchesList;
   std::vector<Jewel *> matchesVector;

   //use oncreate to initialize the board

   Background *background = new Background();
   cursor * cursorx = new cursor();
   ScoreBoard * scoreboard = new ScoreBoard();

   board->scoreboard = scoreboard;
   board->background = background;
   board->cursorx = cursorx;
    
   srand(time(0));
   
  // while(!done){
  
   //TRACE("What is the %d grid[0][0] \n",board->grid[0][0]);
   
   for(int row = 0; row < 8; row++)
   {
     for(int col=0; col <8; col++)
	 {
	   type = 1 + rand() % 7;
  
       Jewel * ptr = new Jewel(type);
     
       Index * my_index =  new Index(row,col);
       TRACE("What is the index ---> initialization %d %d \n", row,col);

       ptr->index = type;
       ptr->setIndex(my_index);
       board->grid[row][col] = ptr;
	 }
   }
 
 Isvalid();  //recursive call to fix the matches on the board

 Isvalid();


}

bool CBmpProDoc::Isvalid()
{
   
	 
  bool found = 1;

   while(found)
   {
   
       found = rowIsValid();
	   if(found)
	   {
         TRACE("First time found a row \n");
	   }

	   while(found)
	   {
         found = rowIsValid();
		 TRACE("Did we find a match by row \n");
	   }

   found = colIsValid();
   if(found)
   {
    TRACE("Did we find one by column \n");
   }
	

    while( found )
    {

       found = colIsValid();
	   TRACE("Did we find 2 match by column \n");
	}
 

 }

 return found == 0; 
}


void CBmpProDoc::deleteBoard()
{

 for(int row = 0; row < 8; row++)
	{ 
      for(int column=0; column<8; column++)
	  {
		 delete board->grid[row][column];
	  }  

   }

}


bool CBmpProDoc::colIsValid()
{

	int match = 0;
	bool flag = 0;
    int type = 0;

	std::vector<Jewel *> matches;

 	for(int column = 0; column < 8; column++)
	{ match=0;
      for(int row=0; row<8; row++)
	  {
        int current_type = board->grid[row][column]->JewelType();

         if(current_type == type)
		 {
            match++;
            matches.push_back(board->grid[row][column]);

		 }
         else if(current_type != type)
		 {
            match = 1;
			type = current_type;
			matches.clear();
			matches.push_back(board->grid[row][column]);

		 }
          
         if(match==3)
		 {
              //change the one in the middle
              match=0;
			  change_middle(matches);
              flag=1;
			  matches.clear();
		 }

	  }
	}


//	TRACE("What is the matches %d \n",match);
    TRACE("Where did we fix match by column \n",flag);
	

	return flag == 1;
}  //lines 23


bool CBmpProDoc::rowIsValid()
{
  	int match = 0;
	bool flag = 0;
    int type = 0;
	std::vector<Jewel *> matches;
    
 	for(int row = 0; row < 8;   row++)
	{ match = 0;
      for(int column=0; column<8; column++)
	  {
	     int current_type = board->grid[row][column]->JewelType();
         if(current_type == type)
		 {
            match++;
	        matches.push_back(board->grid[row][column]);
		 }
         else if(current_type != type)
		 {
             match = 1;
			 type=current_type;
			 matches.clear();
			 matches.push_back(board->grid[row][column]);

		 }
		 
		 if(match==3)
			{
              //change the one in the middle
              match=0;
			  change_middle(matches);
              flag=1;
			  matches.clear();
			}

	  }
	

	  
	}
  
	TRACE("What is the matches %d \n",match);
    TRACE("Where did we fix match by row %d \n",flag);
	

   return flag == 1;
}

void CBmpProDoc::change_middle(std::vector<Jewel*> matches)
{

   
   
 int select_middle = 1;
 
 Jewel * middle;
   
 int num = 1 + rand() % 7;
   
 middle = matches[select_middle];
    
 
 TRACE("What is the size of matches %d \n", matches.size() );

   
 Jewel * ptr = new Jewel(num);
               

 Index * i = middle->getIndex();
            
   
 int c = i->col;
 int r = i->row;
  
 Index * new_index = new Index(r,c);
    
 ptr->setIndex(new_index);

 delete board->grid[r][c];

 board->grid[r][c] = NULL;

 board->grid[r][c] = ptr;

   
 TRACE("What is the <*********change_middle index *************> %d %d \n", i->row,i->col );
   

}


CBmpProDoc::~CBmpProDoc()
{
}

BOOL CBmpProDoc::OnNewDocument()
{
  if (!CDocument::OnNewDocument())
		return FALSE;
    
  
       
   bool done = 0;

   board = new Gameboard();
   
   int type;
   CPoint points;

   //use oncreate to initialize the board

   Background *background = new Background();
   cursor * cursorx = new cursor();
   ScoreBoard * scoreboard = new ScoreBoard();

   board->scoreboard = scoreboard;
   board->background = background;
   board->cursorx = cursorx;
    
   srand(time(0));
   
   for(int row = 0; row < 8; row++)
   {
     for(int col=0; col <8; col++)
	 {
	   type = 1 + rand() % 7;
  
       Jewel * ptr = new Jewel(type);
     
       Index * my_index =  new Index(row,col);
       TRACE("What is the index ---> initialization %d %d \n", row,col);

       ptr->index = type;
       ptr->setIndex(my_index);
       board->grid[row][col] = ptr;
	 }
   }
 
 Isvalid();  //recursive call to fix the matches on the board

 Isvalid();
  
 UpdateAllViews(NULL);

 return TRUE;
} // 28 lines of code in this func
 

/////////////////////////////////////////////////////////////////////////////
// CBmpProDoc serialization

void CBmpProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CBmpProDoc diagnostics

#ifdef _DEBUG
void CBmpProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBmpProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBmpProDoc commands

BOOL CBmpProDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

/*	HBITMAP hImage = (HBITMAP)LoadImage(NULL, lpszPathName, IMAGE_BITMAP,
	0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE);

	m_bitmap.Attach(hImage);

 	m_bitmap.LoadBitmap(IDB_GEM1);

	BITMAP bitmap;

	m_bitmap.GetBitmap(&bitmap);

	m_height = bitmap.bmHeight;
	m_width = bitmap.bmWidth;
*/

	return TRUE;
}

void CBmpProDoc::DeleteContents() 
{


   	//delete the board and then call
    
	delete board->cursorx;
	delete board->background;
    delete board->scoreboard;

  	for( int row = 0; row < 8; row++)
	{
         for(int column=0; column<8;column++)
		 {
      	    delete board->grid[row][column];
		 }
	}

 

	TRACE("THERE IS A CALL TO DELETE CONTENTS \n");


  CDocument::DeleteContents();
}

int CBmpProDoc::removal(std::stack<Jewel *> & jewel_stack)
{
  //;
 return 0;
 
}







