#include "CApp.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>


using std::runtime_error;
using std::cout;
using std::endl;

bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) { 
		throw std::runtime_error("can't SDL_INIT_EVERYTHING");
	}

	if ((Surf_Display = SDL_SetVideoMode(600,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) { 
		throw std::runtime_error("can't SDL_SetVideo_Mode");
	}

	if ((Surf_Board= CSurface::OnLoad("./gfx/board.png")) == NULL) {
		throw std::runtime_error("can't OnLoad ./gfx/board.png");
	}

	if ((Surf_Brick = CSurface::OnLoad("./gfx/box.png")) == NULL) {
		throw std::runtime_error("can't OnLoad ./gfx/box.png");
	}

	if ((Surf_BrickGrey = CSurface::OnLoad("./gfx/box_grey.png")) == NULL) {
		throw std::runtime_error("can't OnLoad ./gfx/box.png");
	}

	//current_shape.Display();
	//board.Display();

	srand(time(0));
	last_tick = SDL_GetTicks();

//	Reset();

    return true;
}


