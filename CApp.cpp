#include "CApp.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

#define BOARD_SIZE_X 10;
#define BOARD_SIZE_Y 10;

CApp::CApp() {
	Surf_Display	= NULL;
	Surf_Board	= NULL;
	Surf_Brick	= NULL;
	Surf_BrickGrey	= NULL;

	Running		= true;
	Lines_Dropped	= 0;
	Current_Speed	= 800;
}



void CApp::DrawBoard(Mult_Line to_draw, int x, int y, int w, int h) { 
	for (Mult_Line_CItr i = to_draw.begin(); i != to_draw.end(); i++) { 
		int _x = x;
		for (Line_CItr j = (*i).begin(); j != (*i).end(); j++) {
			if ((*j) == 1)  
				CSurface::OnDraw(Surf_Display,Surf_Brick,_x,y);
			else if  ((*j) == 2)  
				CSurface::OnDraw(Surf_Display,Surf_BrickGrey,_x,y);
			
			_x += w;
		}
		y += h;
	}
}


void CApp::MoveShape(int x, int y) {
	Shape tmp_shape = current_shape;

	if (x == 0 and y == 0) 
		tmp_shape.Rotate();
	else {
		tmp_shape.cord_x += x;
		tmp_shape.cord_y += y;
	}

	if (y == 0) {
		// side move
		if (board.LegalMove(tmp_shape)) {
			board.RemoveShape(current_shape);

			if (x == 0 and y == 0) 
				current_shape.Rotate();
			else {
				current_shape.cord_x += x;
				current_shape.cord_y += y;
			}

			board.DrawShape(current_shape,1);
		}
	}
	else if (y == 1) { 
		// down move
		if (!board.LegalMove(tmp_shape)) {
			board.DrawShape(current_shape,2);
			current_shape.dropping = 0;
		}
		else {
			board.RemoveShape(current_shape);
			current_shape.cord_x += x;
			current_shape.cord_y += y;
			board.DrawShape(current_shape,1);
		}
	}

}

int CApp::OnExecute() {
	try { 
		OnInit();
	}
	catch(runtime_error e) { 
		cout << "OnInit failed with: " << e.what() << endl;
		return -1;
	}

	SDL_Event Event;

	while(Running) { 
		while(SDL_PollEvent(&Event)) { 
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	// stoping the while from iterating too fast
	// to lower cpu usage
	SDL_Delay(50);

    return 0;
}

int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

