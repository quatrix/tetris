#include "CApp.h"
#include "generic.hpp"

void CApp::OnLoop() {
	int ticks = SDL_GetTicks();

	if (ticks > last_tick + Current_Speed) {
		MoveShape(0,1);
		last_tick = ticks;
	}

	if (current_shape.dropping == 0) {
		int newly_droped_lines = board.RemoveFullLines();
	
		if (newly_droped_lines >0) { 
			Lines_Dropped += newly_droped_lines;
			Current_Speed -= (newly_droped_lines * 10);
		}
 	
		Shape new_shape_yay;
		current_shape = next_shape;
		next_shape = new_shape_yay;
		if (!board.LegalMove(current_shape)) { 
			Running = 0;
		}

	}
}

