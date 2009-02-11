#include "CApp.h"
#include <iostream>
using std::cout; using std::endl;

void CApp::OnRender() {
	CSurface::OnDraw(Surf_Display,Surf_Board,0,0);
	DrawBoard(board.board,55,124,30,30);
	DrawBoard(next_shape.shape,355,124,30,30);
	//board.Display();

	SDL_Flip(Surf_Display);
}

