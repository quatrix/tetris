#ifndef _Board_h
#define _Board_h

#include <vector>
#include "Shape.hpp"


typedef std::vector<int> Line;
typedef std::vector<Line> Mult_Line;
typedef Mult_Line::const_iterator Mult_Line_CItr;
typedef Mult_Line::iterator Mult_Line_Itr;
typedef Line::const_iterator Line_CItr;
typedef Line::iterator Line_Itr;
typedef Line::size_type Line_sz;
typedef Mult_Line::size_type Mult_Line_sz;

class Board  {
	public:
		Board();
		void Display();
		void DrawShape(const Shape&,int);
		void RemoveShape(const Shape&);
		int  RemoveFullLines();
		bool LegalMove(const Shape&);
		
	public:
		Mult_Line board;
		

	private:
		
};

#endif
