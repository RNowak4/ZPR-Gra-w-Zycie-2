/**
*@file View.cpp
*@author Damian Mazurkiewicz
*/
#include "View.h"
#include "controller/Controller.h"

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
	quit_ = false;

	while (!quit_)
	{
		mySDL_.clearScreen(); //Clear screen.
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(&event_);
		}
		mySDL_.renderScreen(); // Render screen.
	}

	mySDL_.close();
}

void View::quit()
{
	quit_ = true;
}