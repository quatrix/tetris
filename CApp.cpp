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


}



void CApp::DrawBoard() { 

	int y = 124;

	for (vector<vector<int> >::const_iterator i = board.board.begin(); i != board.board.end(); i++) { 
		int x = 55;
		for (vector<int>::const_iterator j = (*i).begin(); j != (*i).end(); j++) {
			if ((*j) == 1)  
				CSurface::OnDraw(Surf_Display,Surf_Brick,x,y);
			else if  ((*j) == 2)  
				CSurface::OnDraw(Surf_Display,Surf_BrickGrey,x,y);
			
			x += 30;
		}
		y += 30;
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

    return 0;
}

Uint32 CApp::MoveShapeDown(Uint32 interval, void* param)
{
	SDL_Event event;

	event.type = SDL_USEREVENT;
	event.user.code = 666;
	event.user.data1 = 0;
	event.user.data2 = 0;

	SDL_PushEvent(&event);

	return interval;
}


int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

