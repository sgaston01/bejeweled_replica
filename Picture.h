// Picture.h: interface for the Picture class.
//
//////////////////////////////////////////////////////////////////////
//#include"Mydebug.h"
#include<vector>
#include<list>
#include<stack>

#if !defined(AFX_PICTURE_H__BCA6ADA0_1605_11CD_8662_BE7D9A4D952F__INCLUDED_)
#define AFX_PICTURE_H__BCA6ADA0_1605_11CD_8662_BE7D9A4D952F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class Picture //: public CObject  
{
public:
	Picture();
	virtual ~Picture();
	virtual void Draw(CDC * draw);
    CBitmap bitmap;
};


class Background //: public Picture 
{
public:
   Background();
   Background(CBitmap bit);
   CBitmap * bitmap;
   CBitmap & getBitmap();
   void Draw(CDC * draw);
   CRect bound;

};



class Index 
{
  public:
  Index(int row,int column);
  ~Index();
  //Index * FindIndex(int column,int row);
  int col;
  int row;
};


class Jewel //: public Picture 
{
public:
  int index;
  CPoint points;
  BOOL InBound(CPoint points);
  int JewelType();
  Jewel(int type);
  ~Jewel();
  void setIndex(Index *& location);
  void setBound(CRect bound);
  CRect getBound();
  //void Animation(CPoint point);

  BOOL isBound(CPoint point);//return region.PtInRect(bound); }
  Index * getIndex();
  
  CBitmap *bitmap;
  Index * m_index;
  CRect region;
  int jewel_type;
  UINT m_width;
  UINT m_height;
  
};


class ScoreBoard
{
  public:
  
  ScoreBoard();
  void CalculateScore(std::stack<Jewel *> Number_of_Jewels);
  int do_score(std::stack<Jewel *> jewels , int current_value, int match, int popped );
  int current_score;
  
  void Draw(CDC * pDc);
  void setPointSystem(int scoring_system);
  void DefaultSystem();
  int normal_score_system;
  int double_score_system;
  int previous_score;
  int count;

  CBitmap *score_bitmap;

  private:

  int double_match_points(std::stack<Jewel *> jewel_stack ,int pop_count,int scale); 
   
};



class cursor
{
  public:
  cursor();

  void Draw (CDC * pDC);
  void setCursor(CPoint location);
  
  CPoint getSavePoint(){ return points;   }
  CPoint getBasePoint(){return basepoint; }

  CPoint points;   //first_click
  CPoint basepoint;
  CPoint second_click;
  CBitmap *bitmap;
  int click;
  CRect cursor_bound;

  UINT m_width;
  UINT m_height;
};


class Gameboard : public CObject
{
  public:

  Background * background;
  cursor * cursorx;
  ScoreBoard * scoreboard;

  int num;
 
  Jewel * grid[8][8];
  Gameboard();
  BOOL isValidPoint(CPoint point); //check for point region
  std::vector<Jewel *> isAdjacentROW(cursor * curs,CPoint point);
  std::vector<Jewel *> isAdjacentCOLUMN(cursor * curs,CPoint point);
  BOOL doSwap(const std::vector<Jewel *> & adjacent_jewels);
  
  void change_index(Index * first, Index * second);
  std::stack<Index *> remove();
  
  CRect bound;
  Jewel * getGrid(int r, int c){return grid[r][c];}
  std::stack < Jewel *> & GetMatches();
  std::stack < Jewel *> removals;
  bool column_full(int column);
  int GetMoreMatches(int size);
  Jewel * LookupJewel(CPoint point);
   
  private:

 
  std::stack < Jewel *> & GetMatchbyRow();
  std::stack < Jewel *> & GetMatchbyColumn();

  //will process by row   
  //BOOL isAdjacentbyRow(cursor *curs,CPoint point);
  BOOL isAdjacentbyRow(Jewel *,Jewel *);
  BOOL isAdjacentbyCol(Jewel *,Jewel *);

  //void LookupIndex(savepoint,secondpoint,jewel1,jewel2);
  
  std::vector<Jewel *> find_matchJewels(const std::vector<Jewel *> &);  
  void organize(std::stack<Index *> & invalid_index);
  void shift(int column,int row,Jewel *iter,int r,int flag);
  void reassign_Shift(int column);
  

};



#endif // !defined(AFX_PICTURE_H__BCA6ADA0_1605_11CD_8662_BE7D9A4D952F__INCLUDED_)
