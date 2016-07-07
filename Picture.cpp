// Picture.cpp: implementation of the Picture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "graph.h"
#include "Picture.h"
//#include "DoSwap.h"
//#include"Mydebug.h"

#include<vector>
#include<list>
#include<stack>

#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Picture::Picture()
{

}

Picture::~Picture()
{

}

void Picture::Draw(CDC *draw)
{

}



ScoreBoard::ScoreBoard()
{
   current_score = 0;
   count = -1;
   score_bitmap = new CBitmap;
   score_bitmap->LoadBitmap(IDB_SCORE);
}

void ScoreBoard::CalculateScore(std::stack<Jewel *> Number_of_Jewels)
{
   //recursively look for a match 
    int match = 0;
    int type  = 0;
    int value = 0;
 	int popped = 0;
    int scale = 0;
    normal_score_system=1;

    TRACE ("What is the number of the jewels on the stack %d \n",Number_of_Jewels.size() ); 
    
   // communicate with the gameboard class
   // to set check row and column 
   // to award the basic points
      
	if( normal_score_system == 1){

      
    value = do_score(Number_of_Jewels,value,match,popped);  
    previous_score = value;  
	current_score += value;
	}
   // commumicate with yourself to see if the
   // flag for row and columns are check
   // this means the score class will 
   // look for double scoring 
   // after doing this recursion set the 
   // flags back to the normal staters 

   if( double_score_system == -1)
   {
     
	  current_score  += double_match_points(Number_of_Jewels,popped,scale); 
     
   }


   TRACE("What is the score returned %d \n", value);


}

int ScoreBoard::do_score(std::stack<Jewel *> jewels , int current_value, int match, int popped )
{
   int value = 0;      

	if(!jewels.empty() )
	{
        popped++;        
		
	    if(popped == 3)
		{
           match++;
		   value += 10;
		}
         
		else if(popped==4)
		{
           match++;
           value += 10;
		}
		else if(popped==5)
		{
          value += 10; 
		}
        else if(popped==6)
		{
           value += 20;
		}

		jewels.pop();

	    value += do_score(jewels,current_value, match, popped);
	}
    
	else if( jewels.empty() )
    {
         
       TRACE("What is the value earned %d ", current_value);
	}	

	return  value;
	
	//do_score(jewels,value,popped);
} //function do score will calculate the score
//based on the current point system

// 23 lines 
int ScoreBoard::double_match_points(std::stack<Jewel *> stack_jewel,int popped,int scale) 
{
	
	int score = 0;

	if(!stack_jewel.empty()) 
	{
	  if(popped <= 12)
	  {   
	    if(popped ==0 || popped == 3 || popped == 6 || popped == 9 || popped == 12 )
		{
          previous_score += scale;
		  scale += 10;
		}
	   if(popped == 12)
       {
	     scale = 20;	  
	   }

	}
	else if(popped > 12 && popped <= 18)
	{
        if(popped == 15 || popped == 18 )   
        {
           previous_score += scale;
		}
	   
		if(popped == 18 )
		{
           scale = 50;
		}
	}
     
	else if(popped > 18 && popped <= 24 )
	{
        if( popped == 21 || popped == 24)
		{
           previous_score += scale;
		}
	}

    if( popped >= 27 )
	{           
       previous_score += scale;
	}
	stack_jewel.pop();
	popped++;
	score = double_match_points(stack_jewel, popped, scale);
}

	else if( stack_jewel.empty() )
	{
      score = previous_score += scale;
	}
	
    return score;
}



void ScoreBoard::Draw(CDC * pDC)
{
  CString str;
  
        
  if(count != current_score)
  {
  
    str.Format(_T("%d"),count);
    pDC->TextOut(488,198,str);
    count++;

  }
  
  if(count == current_score )
  {
      str.Format(_T("%d"),count);
      pDC->TextOut(488,198,str);
  }
  

}

void ScoreBoard::setPointSystem(int scoring_system)
{

   if(scoring_system == 1) //will use method 1 for scoring
   {
      normal_score_system = 1;
	  double_score_system = 0;
   }
   
   else if(scoring_system == 2)
   {
      double_score_system = 1;
	  normal_score_system = 0;
   }
}//function setPointSystem is used to change the
//scoring system to allow double or normal points 
//to be earned in the game 

void ScoreBoard::DefaultSystem()
{
  //set the system to normal point scoring
  normal_score_system = 1;
  double_score_system = 0;
   
}//function DefaultSystem changes the scoring
// points to normal mode for checking the 
// gameboard 


//

Background::Background()
{
	
  //load in the background in this function
   bitmap = new CBitmap;
   bitmap->LoadBitmap(IDB_BACKGROUND);
 

   

}

Background::Background(CBitmap bit)
{ 
  //bitmap = new CBitmap;
  //bitmap = &bit;
  //bitmap.LoadBitmap(IDB_BITMAP2);

}

void Background::Draw(CDC * draw)
{
 
  draw->SelectObject(bitmap);
  //draw->BitBlt(0,0,100,100,&dc,0,0,)
}

CBitmap & Background::getBitmap()
{ 
  //;
  return *bitmap;
}

/*CRect Background::lookupRect(CPoint point )
{
  CRect bound;
   
   


  return bound;
}*/


void Jewel::setIndex(Index * &location)
{
 m_index = location;
 //TRACE("what * is the row %d \n",location->row);
 //TRACE("what * is the col %d \n",location->col);
}

Index * Jewel::getIndex()
{
  return m_index;
}

int Jewel::JewelType()
{
 return jewel_type;
}

Jewel::Jewel(int type )
{
	//use cases 
//  CRect r;
  jewel_type = type;
  bitmap = new CBitmap();

  switch ( type )
  {
	 case 1:
     bitmap->LoadBitmap(IDB_GEM1);
     break;

     case 2:
     bitmap->LoadBitmap(IDB_GEM2);
     break;

	 case 3:
     bitmap->LoadBitmap(IDB_GEM3);
	 break;

     case 4:
	 bitmap->LoadBitmap(IDB_GEM4);
     break;

	 case 5:
	 bitmap->LoadBitmap(IDB_GEM8);
     break;

	 case 6:
	 bitmap->LoadBitmap(IDB_GEM6);
     break;

	 case 7:
	 bitmap->LoadBitmap(IDB_GEM7);
     break;


  
  
  }

 

//call below stuff somewhere else 
   BITMAP bmp;

   bitmap->GetBitmap(&bmp);

   
   m_width = bmp.bmWidth;
  
   m_height = bmp.bmHeight;

 //  TRACE("What is the height and the width of the bitmap %d %d \n" ,m_height,m_width);
  //width = bitmap->bmWidth;
  
  //height = bitmap->bmHeight;

}   //once working change the classes 
   // to supporing polymorphism


void Jewel::setBound(CRect bound)
{
  region = bound;
}


CRect Jewel::getBound()
{
  return region;
}
BOOL Jewel::isBound(CPoint point)
{

  POINT point1; 
  BOOL found = 0;
  point1.x = point.x;
  point1.y = point.y;
  
  found = region.PtInRect(point1);

  //if(found==1)
  //return TRUE;

  //else if (found == FALSE)
  return found == TRUE;
}

BOOL Jewel::InBound(CPoint points)
{
  CRect bound;
  bound.SetRect(points.x,points.y,points.x + 32,points.y + 34);
  bound.PtInRect(points);

  return TRUE;
}

Jewel::~Jewel()
{
  TRACE("Calling the destructor jewel \n");
  delete bitmap;
  delete m_index;
}

Index::Index(int r,int column)
{
  col = column;
  row = r;
}

Index::~Index()
{
  TRACE("Removing the index associated with jewel\n");
 
}

Gameboard::Gameboard()
{
   POINT top_left;
   POINT bottom_right;

   top_left.x = 35;
   top_left.y = 32;
   bottom_right.x = 326; 
   bottom_right.y = 296;
   
   bound.SetRect(top_left,bottom_right);

   for(int row = 0; row < 8; row++)
   {
     for(int col=0; col <8; col++)
	 {
	    grid[row][col]=NULL;
		
	 }
   }
}

BOOL Gameboard::isValidPoint(CPoint point)
{
  	BOOL found;
	POINT init_point;
	init_point.x = point.x; 
	init_point.y = point.y;

	found = bound.PtInRect(init_point);
	if(found)
	return 1;
	else 
	return 0;

}

std::vector<Jewel *> Gameboard::isAdjacentCOLUMN(cursor *curs, CPoint secondpoint)
{

  Jewel * jewel1;
  Jewel * jewel2;
  BOOL found=0;  
  std::vector<Jewel *> a;
  //get the second point from the user to check to see if the point is adjacent 
  CPoint savepoint = curs->getSavePoint();
 

  jewel1 = LookupJewel(savepoint);
  jewel2 = LookupJewel(secondpoint);
  
  if( jewel1 == jewel2)
  {

    //don't continue processing the thing
    //any longer 	
  }

   if(jewel1 != NULL && jewel2 != NULL)
 {

  found = isAdjacentbyCol(jewel1,jewel2);  
  // return the adjacent jewels in the vector 
  if( found == TRUE )
  {
    a.push_back(jewel1);
    a.push_back(jewel2);
  }
 }
  /////// else if the jewels are not adjacent then the vector is empty

  return a;
}


std::vector<Jewel *> Gameboard::isAdjacentROW(cursor *curs,CPoint secondpoint)
{
  Jewel * jewel1;
  Jewel * jewel2;
//  Jewe1 * first; //first is the location to check swap
  BOOL found=0;  
  std::vector<Jewel *> adjacent_jewels;
  
  CPoint savepoint = curs->getSavePoint();
  //LookupIndex(savepoint,secondpoint,jewel1,jewel2);
  jewel1 = LookupJewel(savepoint);
  jewel2 = LookupJewel(secondpoint);
  
  if( jewel1 == jewel2)
  { //don't continue processing the thing
	//any longer 	
  }

 if(jewel1 != NULL && jewel2 != NULL)
 {
  found = isAdjacentbyRow(jewel1,jewel2);

  if ( found == TRUE){
     adjacent_jewels.push_back(jewel1);
	 adjacent_jewels.push_back(jewel2);
  }
 
 }

  return adjacent_jewels;

}//lines

//jewel1 refers to the first jewel
//jewel2 refers to the second jewel


BOOL Gameboard::isAdjacentbyRow(Jewel * jewel1,Jewel *jewel2)
{
  BOOL isadjacent = 0;
  Index * user_first_click = jewel1->getIndex();
  Index * user_second_click = jewel2->getIndex();
   //might need to add a get region here
  CPoint user_first_basepoint = jewel1->region.TopLeft();
  CPoint user_second_basepoint= jewel2->region.TopLeft();
 // Mydebug test;

  //check to see if the jewel are adjacent by row
  //TRACE("What is the row of i1 %d ",user_first_click->row);
  //TRACE("What is the row of i2 %d ",user_second_click->row); 

  if(user_first_click->row == user_second_click->row)
  {
      //check to see if the two clicks are in the same 
	  //bound 
      
	  //get the two base points
    int distance = user_first_basepoint.x - user_second_basepoint.x;
        
       if(distance < 0) //to convert to positive int
		distance = distance * -1;

  TRACE("What is the distance %d \n",distance);
  TRACE("What is the width %d \n",jewel1->region.Width());

    if(distance <= jewel1->region.Width()+1 )     
    {
        isadjacent = 1; 
		TRACE("WE CAN SWAP \n");		//test.DoModal();
	}
     
  }
  //further process the function if the clicks
    //have the same col 
    //to process if they are adjacent
     
  return isadjacent==TRUE;

}

BOOL Gameboard::isAdjacentbyCol(Jewel *first ,Jewel *second)
{
   
  Index * first_jewel = first->getIndex(); 
  Index * second_jewel = second->getIndex();
  BOOL found = 0; 
   //might need to add a get region here
  CPoint user_first_basepoint = first->region.TopLeft();
  CPoint user_second_basepoint= second->region.TopLeft();
 

  if(first_jewel->col==second_jewel->col)
  {
   
    int dis = user_first_basepoint.y - user_second_basepoint.y; 
	
	TRACE("What is the dis %d \n",dis);
     
	TRACE("What is the height %d \n",first->region.Height());

	if(dis < 0)
		dis = dis * -1;

	if(dis < first->region.Width() )
    {
	  //TRACE("What is the height % d ",first->region.Height() );
      found = 1;
	}
  }

  return found == TRUE;
}

Jewel * Gameboard::LookupJewel(CPoint point)
{
   BOOL found = 0;
   int c;
   int r;
  
   for(int row = 0; row < 8 && !found; row++)
   {
	 
      for(int col=0; col< 8 && !found; col++)
	  {
         
		  found = grid[row][col]->isBound(point);
		  if(found==1)
		  { 
             TRACE("location %d %d \n",row,col);
			 found = 1;//might need to use found
		     c = col;
		  }          		 
	  }
    
     r = row;
   }
   

   
   if(found)
   {
	 return grid[r][c];
   }

   return NULL;

}
//Precondtion use if the jewels are adjacent
//if not the data is invalid

BOOL Gameboard::doSwap(const std::vector<Jewel *> & adjacent_jewels)
{
   
   Jewel * temp_first;
   Jewel * temp_second;
   bool found = 0;
   std::vector<Jewel *>::const_iterator iter;
   std::stack<Jewel *> stack_count;
   std::stack<Index *> stack_index;

   //revise this
   iter = adjacent_jewels.begin();
   
   temp_first = *iter;
   iter++;
   temp_second = *iter;
   
   //do swap by row
  
  change_index(temp_first->getIndex(),temp_second->getIndex());   

  
  stack_count = GetMatches();
       
 if(!stack_count.empty())
 { 
    stack_index = remove();
     
	TRACE("THERE IS A MATCH from doSwap \n");
//etTimer(message,1,50,NULL);
   

	found = 1;
 }
 else if(stack_count.empty() )
 {
   change_index(temp_second->getIndex(), temp_first->getIndex() );
   found = 0;
 }

 //check to see if there is more  with the GetMatches 


 return found == 1;
}

std::vector<Jewel *> Gameboard::find_matchJewels(const std::vector<Jewel*> & adjacent_jewels)
{ 
  
 std::vector<Jewel *> match_jewels;
 
 int match = 0;
 int jewel_type=0;
 
for(int jewel_count=0; jewel_count <8; jewel_count++)
{
 int current_type = adjacent_jewels[jewel_count]->JewelType();   
 TRACE("What is the jewel type %d \n", current_type);
  
 if(current_type == jewel_type)
 {
   match++;

   match_jewels.push_back(adjacent_jewels[jewel_count]);
 }

 else if(current_type != jewel_type)
 {
   match = 1; 
   match_jewels.clear();
   jewel_type = current_type;
   match_jewels.push_back(adjacent_jewels[jewel_count]);
 }  

 if(match == 3)
 {
	 TRACE("Found a match\n");

 }
 
} //14 lines


 return match_jewels;

}

std::stack<Jewel *> & Gameboard::GetMatches()
{
 
 

 GetMatchbyRow();
 
 GetMatchbyColumn();
 
 return removals;

}


std::stack<Jewel *> & Gameboard::GetMatchbyRow()
{

  	std::vector<Jewel *> matches;

	int match = 0;
    
	int type = 0;

 	for(int row = 0; row < 8; row++)
	{ match=0;
      for(int column=0; column<8; column++)
	  {
		 int current_type = grid[row][column]->JewelType();
             
         if(current_type == type)
		 {
            match++;
            matches.push_back(grid[row][column]);
		    
			if( match==3)
			{
				for(int count=0; count < 3; count++){
                removals.push(matches[count]);
				

			}
				TRACE("is the match a row ***** \n");
			}
		 }
         else if(current_type != type)
		 {
             match = 1;
			 matches.clear();
			 type = current_type;
			 matches.push_back(grid[row][column]);
		 }
          
		 if(match > 3)
		 {
          removals.push(grid[row][column]);
		 }

	  }
     
	}
   
	return removals;
}


std::stack<Jewel *> & Gameboard::GetMatchbyColumn()
{

  	std::vector<Jewel *> matches;
	int match = 0;
    int type = 0;

 	for(int column = 0; column < 8; column++)
	{ match=0;
      for(int row=0; row<8; row++)
	  {
		 int current_type = grid[row][column]->JewelType();
             
         if(current_type == type)
		 {
            match++;
            matches.push_back(grid[row][column]);
		    
           
			if( match==3)
			{
              for(int count=0; count < 3; count++)
              removals.push(matches[count]);
              TRACE("is the match a column ***** \n");

			}
		 }
         else if(current_type != type)
		 {
             match = 1;
			 matches.clear();
			 type = current_type;
		     matches.push_back(grid[row][column]);
		 }
          
		 if(match > 3)
		 {
           removals.push(grid[row][column]);
		 }

	  }
     
	}
	
	return removals;
}//18

std::stack<Index *> Gameboard::remove()
{
  
  Jewel * remove;
  std::stack<Index *> stack_index;
  Index * index;
  int count_removed = 0;
  
TRACE("What is the size of the stack %d",removals.size());

 while (!removals.empty() )
  {
      remove = removals.top();
       
 	  
	  index = remove->getIndex();
      
	  int c = index->col;
	  
	  int r = index->row;
       
      TRACE("what is row and column is deleted %d %d \n",r,c);
	  
	  Index * copy = new Index(r,c);
	  
	  stack_index.push(copy);
      
	  delete grid[r][c];
	  grid[r][c]=NULL;

	  removals.pop();
      count_removed++;
      
	 
 }	   
 
 
 //fix_board(){returns true if stack count > 0}
 //call organize(stack_index) //reversed stack 

 organize(stack_index);

 return stack_index;

}

void Gameboard::change_index(Index * first, Index * second)
{
    
	Jewel * first_jewel = grid[first->row][first->col];
    Jewel * second_jewel = grid[second->row][second->col];
    
//TRACE("What is in first jewel %d \n",first_jewel->JewelType());
//TRACE("What is in second jewel %d \n",second_jewel->JewelType());
	


    Jewel *temp = first_jewel;

    first_jewel = second_jewel;

    second_jewel = temp;

//TRACE("What is in first jewel after change %d \n",first_jewel->JewelType());
//TRACE("What is in second jewel after change %d \n",second_jewel->JewelType());


grid[first->row][first->col] = first_jewel;
grid[second->row][second->col] = second_jewel;

Index * index_temp = first_jewel->getIndex();
Index * index_temp2 = second_jewel->getIndex();
first_jewel->setIndex(index_temp2);

second_jewel->setIndex(index_temp);

    
}//modifies the grid to do valid click


int Gameboard::GetMoreMatches(int size )
{
  TRACE("Did we call this GetMoreMatches \n");

   std::stack<Jewel * > count;
   std::stack<Index * > index;
   int total = 0;

   count = GetMatches();
    
   if( count.size() > 0 ) 
   {
      index = remove();       
      //do score here
      total = index.size(); 
	  total += GetMoreMatches(total);
      TRACE("FOUND MORE MATCHES in the MoreMatches  func\n");
	 
   }

   else if ( count.size() == 0)
   {
     TRACE("STOP GETTING MATCHES");      
   }

 
  return total;
}




////////////////////////////////////////////////////////////////

void Gameboard::organize( std::stack<Index *> & invalid_index)
{
  Jewel * iter;
  int need_fix = 0;
  int flag;

 TRACE("This is the first call to the organize function \n");


while(!invalid_index.empty())
{	
    Index * invalid_spot = invalid_index.top();
    int column = invalid_spot->col;
	TRACE("LIST THE INVALID INDEX -----> %d \n",column);
	int row_x = 0;
	int row = 7;
    flag = 1;

// TRACE("What is the row and column in organize %d %d \n",invalid_spot->row,invalid_spot->col);
  iter = grid[row][column];
  
while(column_full(column) == 0 && flag == 1)
{
  
    
    if(iter == NULL)
    {
      flag = 0;

//	  TRACE("Found a null pointer ------------> \n");

//      TRACE("What is the location where the data is null %d %d \n",row,column);


    }
    else if(iter != NULL)
    {
      flag = 1;
  
    }
   
	if(iter != NULL)
	{
	  row--;
      iter = grid[row][column];
	}

} 
    iter = grid[row][column];
	if( flag == 0 )
	{
     ////   TRACE("In the organize func what is the column to visit \n");  
       // TRACE("Also what is the row to start with recursion %d \n",row);
	   // TRACE("What is the first location null %d %d \n",row,column);	
		//if(iter==NULL)
//		{
//	      TRACE("Before shifting what is the jewel and the index %d %d \n",row,column);
			
	 
//	      TRACE("What is the index to remove %d %d \n", invalid_spot->row, invalid_spot->col);

		
//		}
       row_x = row;
      shift(column,row,iter,row_x,flag);
	
	
	
	}
   invalid_index.pop();

  


}  


//TRACE("NULL pointer = %d \n",null_pointer);

//TRACE("What is the count for fixing %d \n",need_fix);

 




//TRACE("<--------------This is the end call of the organize function------->\n");
}

bool Gameboard::column_full(int column)
{
bool  found = 1;

  Jewel *iter;

  for (int row = 0; row <8; row++)
  {
     iter = grid[row][column];

	 if(iter == NULL)
	 {
         found = 0;
//		 TRACE("Is the function column not full \n");
         
	 }


  }

 return found == 1;

}


void Gameboard::shift( int column,int r, Jewel *iter,int row, int flag)
{


if(row >= 0)
{
 
//TRACE("What data is pass in to recursive function column %d r %d row %d flag %d \n", column,r,row,flag);
        

	 if(iter == NULL)
	 { 
        flag = 0;
        
        if( row-1 >= 0 )
		{
		 iter = grid[row-1][column];
//		 TRACE("What is tahe row and what is the column %d %d \n", row , column);
		
		 shift(column,r,iter,row-1,flag);
//		 TRACE("What is current row that needs to be modified next %d \n", r);
		}
		//else if(row == 0)
		//{
                      
          
		//}
	 }

     else if(iter != NULL )
	 {
  //     TRACE(" The pointer is not null -----------> \n");
       
	   //TRACE("What is the index that is not null --> row r= %d and column = %d \n",r,column);
        
       Index * index = iter->getIndex();
       
	   int current_col = index->col;
	  
	   int current_row = index->row;
      
       TRACE("What is the current index from the jewel that is not null row = %d column = %d \n",current_row,current_col);  
	   TRACE("List the current type %d \n",iter->JewelType() );
	   Jewel *  j;

 	   j = grid[current_row][current_col];

       grid[r][column] = j;
	   
	   Index * i = grid[r][column]->getIndex();
	   i->row=r;

       TRACE("What is the row and column to change %d %d \n",r,column);
        
	   Index * t = grid[r][column]->getIndex();
       
	   TRACE("What is the current location after modifing %d %d \n", t->row,t->col);
       
	   grid[current_row][current_col]=NULL;

	   //delete grid[current_row][current_col];// = NULL;
       
	   TRACE("What is the current location after modifing %d %d \n", t->row,t->col);
       
	   if(row-1 >=0)
	   {
	     iter = grid[row-1][column];
	     shift(column,r-1,iter,row-1,0);
	   }

	}



   }
    
  if(row == 0)
  {
    // TRACE("What is the column to modify %d \n",column);


    reassign_Shift(column);
  }
  // TRACE("did we call the reassign_Shift function \n");



} //14 lines

void Gameboard::reassign_Shift(int start_column)//, int start)
{
       //start at the bottom for the reassign 
   int column = start_column;   
   int row = 7;
   Jewel * iter;
//   Jewel * p;    
   iter = grid[row][column];
   
   TRACE("In the reassign_Shift list the column to change %d \n",start_column);
   
   TRACE("Now iterate over the column before changes are made \n");
    
   /*for(int o = 0; o < 8; o++)
   {
      p = grid[o][column];
      
	  if(p!=NULL)
	  {
    	 TRACE("What is the type %d \n",p->JewelType());
	     Index * my = p->getIndex();
         TRACE("List the index row = %d col = %d \n",my->row,my->col);
	  }
   }*/
   
    
   if(column_full(column) == 0)
   {    
      for( int count = 0; count<8; count++)
	   {
	      int type = 1 + rand() % 7; 
       
         
          if(iter==NULL)
		  {   Index * shift_index = new Index(row,column);
         
		      //CRect rect = background->lookup_byIndex(row,column);
              Jewel * new_jewel = new Jewel(type);
			  shift_index->col = column;
			  shift_index->row = row;
              
			  TRACE("What is the jewel to replace on the board %d %d \n",row,column);
			  
			  
			  new_jewel->setIndex(shift_index);
			  //new_jewel->setBound(rect);
			  grid[row][column] = new_jewel;
			  row--;
              iter = grid[row][column];
          }
          else if (iter != NULL)
		  {
                 Index * invalid = iter->getIndex();
				 //invalid->col = column;
				 invalid->row = row;
                 //iter->setIndex(invalid);
		       
				// CRect rect = background->lookup_byIndex(row,column);
                 row--;
				 //iter->setBound(rect); 
				 iter = grid[row][column];            
          }
         
         
		  
		}


   }

    int u = 0;
	if(column_full(column)==1)
	{
	    while(u < 8 )
		{

          iter = grid[u][column];
          int type = iter->JewelType();
		  Index * i = iter->getIndex();
          CRect bound = iter->getBound();

        
          TRACE(" *** after renewed What is the type %d \n", type);
          TRACE("*** after renewed List loc is the index row = %d col = %d \n",i->row,i->col);
          
		 // TRACE("What is the bound %d ",
           u++;
	   }
    }

} //17 lines 


/////////////////////////////////////////////////////////////////////////a6
cursor::cursor()
{
   bitmap = new CBitmap;
   click = 0;

   bitmap->LoadBitmap(IDB_CURSOR);
   
   BITMAP bmp;

   bitmap->GetBitmap(&bmp);

   
   m_width = bmp.bmWidth;
  
   m_height = bmp.bmHeight;

}

void cursor::setCursor(CPoint location)
{
   points = location;     //store the current user click from the board
   click++;              // increment the count of the user click
                        //  e.g  when click = 0 this indicate the  first time the cursor class
                       //   as retrived a point from the user 
                       //   when click = 1 this will indicate the second time the user click is 
                      //   stored

}



void cursor::Draw(CDC * pDC)
{  
	
   CDC mem;
   mem.CreateCompatibleDC(pDC);
  
   
   CBitmap *bit = mem.SelectObject(bitmap);
   
   COLORREF clrTransparent = mem.GetPixel(0,0);
	
    //keep what is selected into the memory but it will
	//take out the pixel of the specific color
	//and make that color transparent for the memdc; or the images on screen
    //set the cursor 
    // if the cursor lies in the points of the jewels rect

    CPoint basepoint = getBasePoint();
    
             	                                 
	TransparentBlt(	pDC->GetSafeHdc() , basepoint.x, basepoint.y, 30, 30, 
			mem.GetSafeHdc(), 0, 0, 34, 32,clrTransparent); 
	
	mem.SelectObject(bit);
     
    	
}