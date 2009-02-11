#include "Shape.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;


int Shape::RandShape() { 
	const int max_shapes = 7;
	const int bucket_size = RAND_MAX / max_shapes;
	int r;
	
	do
		r = rand() / bucket_size;
	while (r > max_shapes);

	return r;
}

Shape::Shape() {
	static const int shapes[7][5][5] = 
	{ 
		{ // ML
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 },

		},
		{ // L 
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },

		},
		{ // MS
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },

		},
		{ // S 
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 },

		},
		{ // Line
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },

		},
		{ // Square 
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },

		},
		{ // T 
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },

		},

	};	

	/* selecting a random shape and copying 
	   and copying it to the shape vector */

	random_shape = RandShape();

	for (int i = 0; i != 5; i++) { 
		vector<int> _tmp;
		for (int j = 0; j != 5; j++) {
			_tmp.push_back(shapes[random_shape][i][j]);
		}
		shape.push_back(_tmp);
	} 
	
	cord_x = 0;
	cord_y = 0;

	dropping = 1;

}

void Shape::Display() { 
	for (Mult_Line_CItr i = shape.begin(); i != shape.end(); i++) {
		for (Line_CItr j = (*i).begin(); j != (*i).end(); j++)
			cout << *j << ' ';
		
		cout << endl;
	}
	cout << "********************" << endl;
}


void Shape::Rotate() { 
	if (random_shape == SQUARE) 
		return;

	vector<vector<int> > tmp_shape;

	typedef vector<vector<int> >::size_type vvec_sz;
	typedef vector<int>::size_type vec_sz;

	for (vvec_sz i = 0; i != 5; i++) {
		vector<int> _tmp_row;
		for (vec_sz j = 4; j != -1; j--) {
			_tmp_row.push_back(shape[j][i]);
		}
		tmp_shape.push_back(_tmp_row);
	} 	

	shape = tmp_shape;	
}


