#include "CApp.h"

void CApp::OnLoop() {
	if (current_shape.dropping == 0) {
		if(board.RemoveFullLines()) 
			Lines_Dropped++;
 
		Shape new_shape_yay;
		current_shape = new_shape_yay;
		if (!board.LegalMove(current_shape)) { 
			Running = 0;
		}

	}
}

