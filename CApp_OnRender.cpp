#include "CApp.h"
#include <iostream>
using std::cout; using std::endl;

void CApp::OnRender() {
	CSurface::OnDraw(Surf_Display,Surf_Board,0,0);
	DrawBoard();
	//board.Display();

	SDL_Flip(Surf_Display);
}

