/**
*@file View.cpp
*@author Damian Mazurkiewicz
*/
#include "View.h"

void View::drawCreature()
{
	
}

void View::getController(Controller* controller)
{
	controller_ = controller;
}


void View::drawCreatureInfo()
{
	
}
void View::drawBackground()
{
	
}

void View::run()
{
	mySDL_.init();
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event_) != 0)
		{
			SDL_RenderClear(mySDL_.renderer_);
			//User requests quit
			if (event_.type == SDL_QUIT)
			{
				quit = true;
			}
			SDL_RenderPresent(mySDL_.renderer_);
		}
	}

	mySDL_.close();
}