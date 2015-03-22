/**
*@file View.cpp
*@author Damian Mazurkiewicz
*/
#include "View.h"
#include  "Model/Model.h"
#include "controller/Controller.h"
View::View() : mySDL_(), controller_(nullptr), event_(), quit_(false)
{
	camera_.x = 0; 
	camera_.y = 0; 
	camera_.w = SCREEN_WIDTH; 
	camera_.h = SCREEN_HEIGHT;
}
void View::drawCreature(const Animal::LocationData& data)
{
	//Dla testów zrobione na szybko obracanie siê potworków.
	static double angle = 0;
	mySDL_.draw(&camera_, Assets::getInstance().carnivore_, data.coordinates_.x, data.coordinates_.y, true, angle, 150);
	angle += 0.01;
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
	int backgrWidth; int backgrHeight;
	SDL_QueryTexture(Assets::getInstance().grass_, nullptr, nullptr, &backgrWidth, &backgrHeight);

	int xOffset = - (camera_.x%backgrWidth);
	int yOffset = -(camera_.y%backgrHeight);

	for (int i = xOffset; i < camera_.w; i += backgrWidth)
	{
		for (int j = yOffset; j < camera_.h; j += backgrHeight)
		{
			mySDL_.draw(nullptr, Assets::getInstance().grass_, i, j);
		}
	}
}

void View::run()
{
	
	mySDL_.init();	///Initialize new SDL Screen with renderer
	mySDL_.setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	mySDL_.setWindowTitle("Gra w Zycie.");

	Assets::getInstance().loadAssets(mySDL_); ///Loading all neccesary files.

	boost::timer timer; 

	quit_ = false;

	

	while (!quit_)
	{
		mySDL_.clearScreen(); //Clear screen.
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(&event_);
		}

		drawBackground();
		controller_->update(timer);
		
	

		mySDL_.renderScreen(); // Render screen.
	}

	Assets::getInstance().disposeAssets(); ///Disposing  all loaded files.
	mySDL_.close();
}

void View::quit()
{
	quit_ = true;
}

void View::moveCamera(int x, int y)
{
	camera_.x += x;
	camera_.y += y;
}

const SDL_Rect & View::getCamera()
{
	return camera_;
}