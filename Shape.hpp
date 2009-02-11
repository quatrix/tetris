#ifndef _Shape_h
#define _Shape_h

#include <vector>
using std::vector;

typedef vector<int> Line;
typedef vector<Line> Mult_Line;
typedef Mult_Line::const_iterator Mult_Line_CItr;
typedef Mult_Line::iterator Mult_Line_Itr;
typedef Line::const_iterator Line_CItr;
typedef Line::iterator Line_Itr;

class Shape  {
	public:
		Shape();
		void Display();
		void Rotate();
		

	public:
		Mult_Line shape;

		// shape cordinates
		int cord_x;
		int cord_y; 


		// is it dropping
		int dropping;

		enum Shapes {
			ML,
			L,
			MS,
			S,
			LINE,
			SQUARE,
			T
		};	 

		int RandShape();

	private:
		int random_shape;
		
};

#endif
