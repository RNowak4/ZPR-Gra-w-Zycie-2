/**
*@file View.cpp
*@author Damian Mazurkiewicz
*/
#include "View.h"
#include  "../Model/Model.h"
#include "../Controller/Controller.h"
View::View() : mySDL_(), controller_(nullptr), event_(), quit_(false)
{
	camera_.x = 0; 
	camera_.y = 0; 
	camera_.w = SCREEN_WIDTH; 
	camera_.h = SCREEN_HEIGHT;
}
void View::drawCreature(const Animal::LocationData& data)
{
	//This code makes no sense it is only for rotating pictures ( testing purposes).
	static double angle = 0;
	mySDL_.draw(&camera_, Assets::getInstance().carnivore_, data.coordinates_.x, data.coordinates_.y, true, angle, 150);
	angle += 0.1;
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
	mySDL_.setWindowTitle("Game of life.");

	Assets::getInstance().loadAssets(mySDL_); ///Loading all neccesary files.

	using namespace std::chrono;
	
	high_resolution_clock::time_point time = high_resolution_clock::now();
	high_resolution_clock::time_point frame = high_resolution_clock::now();
	duration<double> time_span;

	int fpsCounter = 0;

	quit_ = false;

	

	while (!quit_)
	{
		//Measuring time of new frame. 
		frame = high_resolution_clock::now();
		mySDL_.clearScreen(); //Clear screen.

		//Sending input from user to conroller to handle it.
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(&event_);
		}

		drawBackground();

		//FPS counter only for testing purposes!
		++fpsCounter;
		time_span = duration_cast<duration<double>>(high_resolution_clock::now() - time);
		if (time_span.count() >= 1)
		{
			std::cout << fpsCounter << " FPS" <<std::endl;
			fpsCounter = 0;
			time = high_resolution_clock::now();
		}


		controller_->update();
		
		mySDL_.renderScreen(); // Render screen.

		//We keep the frames per second at relatively fixed amount. 
		time_span = duration_cast<duration<double>>(high_resolution_clock::now() - frame);
		if (time_span.count()< FRAME_TIME)
			SDL_Delay((FRAME_TIME - time_span.count()) * 1000);
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
