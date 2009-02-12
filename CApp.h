#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CSurface.h"
#include "CEvent.h"
#include "Shape.hpp"
#include "Board.hpp"
#include "generic.hpp"


class CApp : public CEvent {
	private:
	        bool    	Running;
		int 		CurrentPlayer;
		int		Winner;

		SDL_Surface*	Surf_Display;
		SDL_Surface*	Surf_Board;
		SDL_Surface*	Surf_Brick;
		SDL_Surface*	Surf_BrickGrey;

		Shape		current_shape;
		Shape		next_shape;
		Board		board;
		int		Lines_Dropped;
		int		Current_Speed;
		int		last_tick;

	public:

	private:
//		SDL_Surface*	Surf_Grid;

	private:

	public: 
		void DrawBoard(Mult_Line,int,int,int,int);
		void MoveShape(int,int);
		static Uint32 MoveShapeDown(Uint32, void*);

	public:
		CApp();
	public:

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event* Event);
		void OnUser(Uint8 type, int code, void* data1, void* data2);
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnExit();

		void OnLoop();

		void OnRender();

		void OnCleanup();
};


#endif

