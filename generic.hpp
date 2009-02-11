#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

typedef std::vector<int> Line;
typedef std::vector<Line> Mult_Line;
typedef Mult_Line::const_iterator Mult_Line_CItr;
typedef Mult_Line::iterator Mult_Line_Itr;
typedef Line::const_iterator Line_CItr;
typedef Line::iterator Line_Itr;
typedef Line::size_type Line_sz;
typedef Mult_Line::size_type Mult_Line_sz;
