#include "CApp.h"
#include <iostream>

void CApp::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) { 
		case SDLK_ESCAPE: 
			Running = 0;
			break;

		case SDLK_LEFT:
			MoveShape(-1,0);
			break;

		case SDLK_RIGHT:
			MoveShape(1,0);
			break;

		case SDLK_DOWN:
			MoveShape(0,1);
			break;

		case SDLK_UP:
			MoveShape(0,0);
			break;

	}
}

void CApp::OnUser(Uint8 type, int code, void* data1, void* data2) {
	if (code == 666) 
		MoveShape(0,1);
}

void CApp::OnExit() { 
	Running = false;
}


