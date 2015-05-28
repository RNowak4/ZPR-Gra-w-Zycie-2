/**
*@file View.cpp
* POZDROWIENIA DLA RADKA
*@author Damian Mazurkiewicz
*/

#include <sstream>
#include "View.h"
#include  "../Model/Model.h"
#include "../Model/Constants.h"
#include "../Model/Parameters.h"
#include "TimeEvent.h"
#include "../Controller/Controller.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FPS = 50;
const double FRAME_TIME = 1.0 / FPS;
const int FRAMES_COUNT_TO_UPDATE = 10;
const std::vector<std::string> HELP{ "Game of life",
									 "Click on the creature to see its view range and parameters.",
									 "Press UP,DOWN,LEFT,RIGHT to move camera on the map.",
									 "Press P to pause simulation",
									 "Press H to exit help menu.",
									 "Press Esc to end simulation"};

View::View() : mySDL_(), controller_(nullptr), event_(), quit_(false)
{
	camera_.x = 0; 
	camera_.y = 0; 
	camera_.w = SCREEN_WIDTH; 
	camera_.h = SCREEN_HEIGHT;
}

void View::drawCreature(const LocationData& data)
{
	Assets::TextureID texId;
	if (data.animalType_ == HERBIVORE)
		texId = Assets::HERBIVORE;
	else
		texId = Assets::CARNIVORE;

	mySDL_.draw(camera_, Assets::getInstance().get(texId), data.coordinates_.x, data.coordinates_.y, true, data.lookingAngle);
	
}

void View::getController(Controller* controller)
{
	controller_ = controller;
}

void View::drawCreatureInfo(const std::pair<const LocationData*, const AnimalData*> & data)
{
	drawEyeshot(*data.first);

	int fontHeight = 15;
	int margin = 5;

	int x = data.first->coordinates_.x; 
	int y = data.first->coordinates_.y;

	std::shared_ptr<TTF_Font> font = Assets::getInstance().get(Assets::DEFAULT_FONT);

	auto vec1 = &data.second->returnPairVector();
	auto vec2 = &data.second->returnStringVector();

	SDL_Rect frame	{ 
					  x + Parameters::adultWidth / 2,
					  y - Parameters::adultHeigth / 2,
					  150,
					  2 * margin + (vec1->size() + vec2->size())*fontHeight 
					};

	mySDL_.drawFrame(camera_, frame,Assets::getInstance().get(Assets::FRAME_BACKGROUND));
	SDL_Color col{ 0, 0, 0, 0 };
	
	
	int lineCount = 0;
	std::stringstream ss;
	
	for (auto i = vec1->begin(); i != vec1->end(); ++i, ++lineCount)
	{
		ss <<(*i).first << " : " << (*i).second;
		mySDL_.renderText(camera_, font, ss.str(), frame.x + margin, frame.y + margin + lineCount*fontHeight, col);
		ss.str("");
	}
	for (auto i = vec2->begin(); i != vec2->end(); ++i, ++lineCount)
	{
		mySDL_.renderText(camera_, font, (*i), frame.x + margin , frame.y + margin + lineCount*fontHeight, col);
	}
}

void View::drawBackground() 
{
	int backgrWidth; 
	int backgrHeight;
	SDL_Rect camera{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	shared_ptr<SDL_Texture> tex = Assets::getInstance().get(Assets::GRASS);

	SDL_QueryTexture(tex.get(), nullptr, nullptr, &backgrWidth, &backgrHeight);

	int xOffset = - (camera_.x%backgrWidth);
	int yOffset = -(camera_.y%backgrHeight);

	for (int i = xOffset; i < camera_.w; i += backgrWidth)
	{
		for (int j = yOffset; j < camera_.h; j += backgrHeight)
		{
			mySDL_.draw(camera, tex, i, j);
		}
	}
}

void View::run()
{
	try
	{
		mySDL_.init();	///Initialize new SDL Screen with renderer
	}
	catch (InitializingSdlHelperException& e)
	{
		mySDL_.close();
		return;
	}

	mySDL_.setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	mySDL_.setWindowTitle("Game of life");

	try
	{
		Assets::getInstance().loadAssets(mySDL_); ///Loading all neccesary files.
	}
	catch (LoadingAssetsException& e)
	{
		return;
	}

	using namespace std::chrono;
	
	//Time points for time measuring
	high_resolution_clock::time_point second = high_resolution_clock::now();
	high_resolution_clock::time_point frame = high_resolution_clock::now();
	duration<double> time_span;

	int fpsCounter = 0;

	quit_ = false;

	
	//Main loop of program
	while (!quit_)
	{
		//Measuring time of new frame. 
		frame = high_resolution_clock::now();
		mySDL_.clearScreen(); //Clear screen.

		//Sending input from user to conroller to handle it.
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(event_);
		}

		drawBackground();

		
		++fpsCounter;
		if (fpsCounter = FRAMES_COUNT_TO_UPDATE)
		{
			controller_->handleEvent(TimeEvent());
		}
		
		


		controller_->update();
		mySDL_.renderText(camera_, Assets::getInstance().get(Assets::DEFAULT_FONT), "PRESS H FOR HELP", camera_.x, camera_.y, SDL_Color{ 0xff, 0xff, 0xff, 0 });
		
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

void View::drawEyeshot(const LocationData & dat)
{
	double toRadians = M_PI/180;
	
	int x1 = dat.coordinates_.x;
	int y1 = dat.coordinates_.y;

	double angleA = (dat.lookingAngle - (int)(dat.lookingRad / 2))*toRadians; 
	double angleB = (dat.lookingAngle + (dat.lookingRad / 2))*toRadians;;

	int x2 = x1 + dat.sightLen_*std::cos(angleA);
	int y2 = y1 + dat.sightLen_*std::sin(angleA);

	int x3 = x1 + dat.sightLen_*std::cos(angleB);
	int y3 = y1 + dat.sightLen_*std::sin(angleB);

	SDL_Color col{ 0xff, 0, 0, 0 };

	for (double angle = angleA; angle <= angleB; angle+=(toRadians/2))
	{
		mySDL_.drawPoint(camera_,
			x1 + dat.sightLen_*std::cos(angle),
			y1 + dat.sightLen_*std::sin(angle),
			col);
		mySDL_.drawPoint(camera_,
			x1 + 1 + dat.sightLen_*std::cos(angle),
			y1 + 1 + dat.sightLen_*std::sin(angle),
			col);
	}

	mySDL_.drawLine(camera_, x1, y1, x2, y2, col);
	mySDL_.drawLine(camera_, x1, y1, x3, y3, col);
}

void View::drawHelp()
{
	int margin = 5;
	int fontHeight = 15;
	SDL_Rect frame{ camera_.x, camera_.y + 30, SCREEN_WIDTH/2, fontHeight*HELP.size() + 2 * margin };
	mySDL_.drawFrame(camera_, frame, Assets::getInstance().get(Assets::FRAME_BACKGROUND));
	for (int i = 0; i < HELP.size(); ++i)
	{
		mySDL_.renderText(camera_, Assets::getInstance().get(Assets::DEFAULT_FONT), HELP[i]
			, frame.x + margin, frame.y + margin + i*fontHeight, SDL_Color{ 0, 0, 0, 0 });
	}
}