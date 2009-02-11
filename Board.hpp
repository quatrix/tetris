#ifndef _Board_h
#define _Board_h

#include <vector>
#include "Shape.hpp"
#include "generic.hpp"


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
