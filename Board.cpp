#include "Board.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

Board::Board() {
	Line _line(10,0);
	Mult_Line _board(13,_line);

	board = _board;
}


void Board::Display() { 
	for (Mult_Line_CItr i = board.begin(); i != board.end(); i++) {
		for (Line_CItr j = (*i).begin(); j != (*i).end(); j++)
			cout << *j << ' ';
		
		cout << endl;
	}
	cout << "********************" << endl;
}

bool Board::LegalMove(const Shape& shape) {
	for (Mult_Line_sz i = 0 ; i != shape.shape.size(); i++) {
		for (Line_sz j = 0 ; j != shape.shape[i].size(); j++) {
			if (shape.shape[i][j] != 0) {
				if ((i+shape.cord_y) > 12)
					return false;
		
				if ((j+shape.cord_x) > 9) 
					return false;

				if (board[i+shape.cord_y][j+shape.cord_x] == 2) 
					return false;
			}
		}
	}

	return true;
}

void Board::DrawShape(const Shape& shape,int s) {
	for (Mult_Line_sz i = 0 ; i != shape.shape.size(); i++) {
		for (Line_sz j = 0 ; j != shape.shape[i].size(); j++) {
			if (shape.shape[i][j] != 0) 
				board[i+shape.cord_y][j+shape.cord_x] = s;
		}
	}
}

void Board::RemoveShape(const Shape& shape) {
	for (Mult_Line_sz i = 0 ; i != shape.shape.size(); i++) {
		for (Line_sz j = 0 ; j != shape.shape[i].size(); j++) {
			if (shape.shape[i][j] != 0)
				board[i+shape.cord_y][j+shape.cord_x] = 0;
		}
	}

}

int Board::RemoveFullLines() { 
	int rem_lines = 0;
	for (Mult_Line_Itr i = board.begin(); i != board.end(); i++) {
		if (find((*i).begin(),(*i).end(),0) == (*i).end()) {
			board.erase(i);
			Line new_line(10,0);
			board.insert(board.begin(),new_line);
			rem_lines++;
		}
	}
	
	return rem_lines;
}
