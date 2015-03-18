/**
*@file View.cpp
*@author Damian Mazurkiewicz
*/
#include "View.h"
#include "controller/Controller.h"
View::View() : mySDL_(), controller_(nullptr), event_(), quit_(false)
{
	camera_.x = 0; 
	camera_.y = 0; 
	camera_.w = SCREEN_WIDTH; 
	camera_.h = SCREEN_HEIGHT;
}
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
	mySDL_.draw(Assets::getInstance().grass_, 0, 0);
}

void View::run()
{
	
	mySDL_.init();
	mySDL_.setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	mySDL_.setWindowTitle("Gra w Zycie.");
	Assets::getInstance().loadAssets(mySDL_);

	boost::timer timer; 

	quit_ = false;

	while (!quit_)
	{
		mySDL_.clearScreen(); //Clear screen.
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(&event_);
		}
		controller_->update(timer);
		drawBackground();

		mySDL_.renderScreen(); // Render screen.
	}

	Assets::getInstance().disposeAssets();
	mySDL_.close();
}

void View::quit()
{
	quit_ = true;
}