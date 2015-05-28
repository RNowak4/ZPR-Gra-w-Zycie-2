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
#include "Graphics.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FPS = 50;
const double FRAME_TIME = 1.0 / FPS;
const int FRAMES_COUNT_TO_UPDATE = 10;
const std::vector<std::string> HELP{"\"Game of Life\" help:",
									 "Click on the creature to see its view range and parameters.",
									 "Press UP,DOWN,LEFT,RIGHT to move camera on the map.",
									 "Press P to pause simulation",
									 "Press H to exit help menu.",
									 "Press Esc to end simulation"};
auto getGraphics = Graphics::getInstance;

View::View() : controller_(nullptr), event_(), quit_(false)
{
	camera_.x = 0; 
	camera_.y = 0; 
	camera_.w = SCREEN_WIDTH; 
	camera_.h = SCREEN_HEIGHT;
}

void View::drawCreature(const LocationData& data)
{
	Graphics::TextureID texId;
	if (data.animalType_ == HERBIVORE)
		texId = Graphics::HERBIVORE;
	else
		texId = Graphics::CARNIVORE;

	getGraphics().draw(camera_, getGraphics().get(texId), data.coordinates_.x, data.coordinates_.y, true, data.lookingAngle);
	
}

void View::getController(Controller* controller)
{
	controller_ = controller;
}

void View::drawCreatureInfo(const std::pair<const LocationData*, const AnimalData*> & data)
{
	drawEyeshot(*data.first);

	int margin = 5;

	int x = data.first->coordinates_.x; 
	int y = data.first->coordinates_.y;

	std::shared_ptr<TTF_Font> font = getGraphics().get(Graphics::DEFAULT_FONT);

	auto vec1 = &data.second->returnPairVector();
	auto vec2 = &data.second->returnStringVector();

	SDL_Rect frame	{ 
					  x + Parameters::adultWidth / 2,
					  y - Parameters::adultHeigth / 2,
					  150,
					  2 * margin + (vec1->size() + vec2->size())* Graphics::DEFAULT_FONT_SIZE
					};

	getGraphics().drawFrame(camera_, frame, getGraphics().get(Graphics::FRAME_BACKGROUND));
	SDL_Color col{ 0, 0, 0, 0 };
	
	
	int lineCount = 0;
	std::stringstream ss;
	
	for (auto i = vec1->begin(); i != vec1->end(); ++i, ++lineCount)
	{
		ss <<(*i).first << " : " << (*i).second;
		getGraphics().renderText(camera_, font, ss.str(), frame.x + margin, frame.y + margin + lineCount* Graphics::DEFAULT_FONT_SIZE, col);
		ss.str("");
	}
	for (auto i = vec2->begin(); i != vec2->end(); ++i, ++lineCount)
	{
		getGraphics().renderText(camera_, font, (*i), frame.x + margin, frame.y + margin + lineCount* Graphics::DEFAULT_FONT_SIZE, col);
	}
}

void View::drawBackground() 
{
	int backgrWidth; 
	int backgrHeight;
	SDL_Rect camera{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	shared_ptr<SDL_Texture> tex = getGraphics().get(Graphics::GRASS);

	SDL_QueryTexture(tex.get(), nullptr, nullptr, &backgrWidth, &backgrHeight);

	int xOffset = - (camera_.x%backgrWidth);
	int yOffset = -(camera_.y%backgrHeight);

	for (int i = xOffset; i < camera_.w; i += backgrWidth)
	{
		for (int j = yOffset; j < camera_.h; j += backgrHeight)
		{
			getGraphics().draw(camera, tex, i, j);
		}
	}
}

void View::run()
{

	using namespace std::chrono;
	
	//Time points for time measuring
	high_resolution_clock::time_point second = high_resolution_clock::now();
	high_resolution_clock::time_point frame = high_resolution_clock::now();
	duration<double> time_span;

	int fpsCounter = 0;

	quit_ = false;
	getGraphics().setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	
	//Main loop of program
	while (!quit_)
	{
		//Measuring time of new frame. 
		frame = high_resolution_clock::now();
		getGraphics().clearScreen(); //Clear screen.

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
		getGraphics().renderText(camera_, getGraphics().get(Graphics::DEFAULT_FONT), "PRESS H FOR HELP", camera_.x, camera_.y, SDL_Color{ 0xff, 0xff, 0, 0 });
		
		getGraphics().renderScreen(); // Render screen.

		//We keep the frames per second at relatively fixed amount. 
		time_span = duration_cast<duration<double>>(high_resolution_clock::now() - frame);
		if (time_span.count()< FRAME_TIME)
			SDL_Delay((FRAME_TIME - time_span.count()) * 1000);
	}

	Graphics::dispose(getGraphics());
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
		getGraphics().drawPoint(camera_,
			x1 + dat.sightLen_*std::cos(angle),
			y1 + dat.sightLen_*std::sin(angle),
			col);
		getGraphics().drawPoint(camera_,
			x1 + 1 + dat.sightLen_*std::cos(angle),
			y1 + 1 + dat.sightLen_*std::sin(angle),
			col);
	}

	getGraphics().drawLine(camera_, x1, y1, x2, y2, col);
	getGraphics().drawLine(camera_, x1, y1, x3, y3, col);
}

void View::drawHelp()
{
	int margin = 5;
	SDL_Rect frame{ camera_.x + SCREEN_WIDTH/4, camera_.y + 30, SCREEN_WIDTH/2, Graphics::DEFAULT_FONT_SIZE*HELP.size() + 2 * margin };
	getGraphics().drawFrame(camera_, frame, getGraphics().get(Graphics::FRAME_BACKGROUND));
	for (int i = 0; i < HELP.size(); ++i)
	{
		getGraphics().renderText(camera_, getGraphics().get(Graphics::DEFAULT_FONT), HELP[i]
			, frame.x + margin, frame.y + margin + i* Graphics::DEFAULT_FONT_SIZE, SDL_Color{ 0, 0, 0, 0 });
	}
}