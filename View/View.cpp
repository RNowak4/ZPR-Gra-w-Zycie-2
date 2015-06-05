/**
Definitions of View methods.
*@author Damian Mazurkiewicz
*/

#include <sstream>
#include "View.h"
#include  "../Model/Model.h"
#include "../Model/Constants.h"
#include "../Controller/Controller.h"
#include "../Exception/GameOfLifeException.h"

const int View::SCREEN_WIDTH = 800;
const int View::SCREEN_HEIGHT = 600;
const int View::FPS = 50;
const double View::FRAME_TIME = 1.0 / FPS;
const int View::DEFAULT_LINE_HEIGHT = 13;
const int View::HELP_LINE_HEIGHT = 20;
const int View::MARGIN_SIZE = 5;
const int View::DESCRIPTION_FRAME_WIDTH = 150;
const int View::HELP_FRAME_WIDTH = 550;

const std::vector<std::string> View::HELP = { "\"Game of Life\" help:",
									 "*Click on the creature to see its view range and parameters.",
									 "*Press [UP],[DOWN],[LEFT],[RIGHT] to move camera on the map.",
									 "*Press [W] to zoom in, [S] to zoom out.",
									 "*Press [A] to slow down simulation, [D] to speed it up.",
									 "*Press [P] to pause simulation.",
									 "*Press [H] to exit help menu.",
									 "*Press [Esc] to end simulation."};

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
	/*Choose proper texture to draw, basing on animal type.*/
	Graphics::TextureID texId;
	if (data.animalType_ == HERBIVORE)
	{
		if (data.animalSex_ == MALE)
		{
			texId = Graphics::HERBIVORE_GROWN_MALE;
		}
		else
		{
			texId = Graphics::HERBIVORE_GROWN_FEMALE;
		}
	}
	else if (data.animalType_ == CARNIVORE)
	{
		if (data.animalSex_ == MALE)
		{
			texId = Graphics::CARNIVORE_GROWN_MALE;
		}
		else
		{
			texId = Graphics::CARNIVORE_GROWN_FEMALE;
		}
	}
	else if (data.animalType_ == HERBIVORE_CHILD)
	{
		texId = Graphics::HERBIVORE_CHILD;
	}
	else
	{
		texId = Graphics::CARNIVORE_CHILD;
	}

	getGraphics().draw(camera_, getGraphics().get(texId), 
					   static_cast<int>(data.coordinates_.x),
					   static_cast<int>(data.coordinates_.y),
					   true, data.lookingAngle);
}


void View::drawCreatureInfo(const std::pair<const LocationData*, const AnimalData*> & data)
{
	drawEyeshot(*data.first);

	int x = static_cast<int>(data.first->coordinates_.x); 
	int y = static_cast<int>(data.first->coordinates_.y);

	std::shared_ptr<TTF_Font> font = getGraphics().get(Graphics::DEFAULT_FONT);

	const std::string& action = data.second->returnActionName();
	auto vec1 = &data.second->returnPairVector();
	auto vec2 = &data.second->returnStringVector();
	
	/*Calculating the position of the frame with creature description.*/
	SDL_Rect frame	{ 
					  x + Parameters::adultWidth / 2,
					  y - Parameters::adultHeigth / 2,
					  DESCRIPTION_FRAME_WIDTH,
					  2 * MARGIN_SIZE + (1+vec1->size() + vec2->size())* DEFAULT_LINE_HEIGHT
					};
	if (frame.x +frame.w > Parameters::mapWidth)
	{
		frame.x = Parameters::mapWidth - frame.w/getScale();
	}
	if (frame.y + frame.h > Parameters::mapHeight)
	{
		frame.y = Parameters::mapHeight - frame.h / getScale();
	}
	if (frame.x < 0)
	{
		frame.x = 0;
	}
	if (frame.y < 0)
	{
		frame.y = 0;
	}

	getGraphics().drawFrame(camera_, frame, getGraphics().get(Graphics::FRAME_BACKGROUND));

	SDL_Color col{ 0, 0, 0, 0 };
	int lineCount = 0;
	std::stringstream ss;

	/*Write current action.*/
	getGraphics().renderText(camera_, font, action,
		getGraphics().getScaledPosition(frame.x + MARGIN_SIZE, camera_.x),
		getGraphics().getScaledPosition(frame.y, camera_.y) + MARGIN_SIZE + lineCount* DEFAULT_LINE_HEIGHT,
		col);
	++lineCount;
	
	/*Write creature factors.*/
	for (auto i = vec1->begin(); i != vec1->end(); ++i, ++lineCount)
	{
		ss <<(*i).first << " : " << (*i).second;
		getGraphics().renderText(camera_, font, ss.str(), 
			getGraphics().getScaledPosition(frame.x + MARGIN_SIZE, camera_.x),
			getGraphics().getScaledPosition(frame.y, camera_.y) + MARGIN_SIZE + lineCount* DEFAULT_LINE_HEIGHT,
			col);
		ss.str("");
	}
	/*Write creature states.*/
	for (auto i = vec2->begin(); i != vec2->end(); ++i, ++lineCount)
	{
		getGraphics().renderText(camera_, font, (*i),
			getGraphics().getScaledPosition(frame.x + MARGIN_SIZE, camera_.x),
			getGraphics().getScaledPosition(frame.y, camera_.y) + MARGIN_SIZE + lineCount* DEFAULT_LINE_HEIGHT,
			col);
	}
}

void View::drawBackground() 
{
	int backgrWidth; 
	int backgrHeight;
	shared_ptr<SDL_Texture> tex = getGraphics().get(Graphics::GRASS);

	SDL_QueryTexture(tex.get(), nullptr, nullptr, &backgrWidth, &backgrHeight);

	for (int i = 0; i < Parameters::mapWidth; i += backgrWidth-8)
	{
		for (int j = 0; j < Parameters::mapHeight; j += backgrHeight-8)
		{
			getGraphics().draw(camera_, tex, i, j);
		}
	}
}

void View::run(Controller* controller)
{
	if (controller == nullptr)
	{
		throw InitalizingViewException();
	}
	controller_ = controller;
	
	/*To maintain constant number of FPS.*/
	using namespace std::chrono;
	high_resolution_clock::time_point frame = high_resolution_clock::now();
	duration<double> time_span;

	quit_ = false;

	getGraphics().setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	/*Main loop of program.*/
	while (!quit_)
	{
		/*Measuring time of new frame.*/ 
		frame = high_resolution_clock::now();

		getGraphics().clearScreen(); 

		/*Sending input from user to conroller to handle it.*/
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(event_);
		}

		drawBackground();
		controller_->update();
		getGraphics().renderText(camera_, getGraphics().get(Graphics::HELP_FONT), "PRESS H FOR HELP", camera_.x, camera_.y, SDL_Color{ 0xff, 0xff, 0, 0 });
		
		getGraphics().renderScreen(); 

		/*Keep the frames per second number at relatively fixed amount. */
		time_span = duration_cast<duration<double>>(high_resolution_clock::now() - frame);
		if (time_span.count()< FRAME_TIME)
			SDL_Delay(static_cast<Uint32>((FRAME_TIME - time_span.count()) * 1000));
	}

	Graphics::dispose(getGraphics());
}

void View::quit()
{
	quit_ = true;
}

void View::moveCamera(int dx, int dy)
{
	camera_.x += dx;
	camera_.y += dy;
}

const SDL_Rect& View::getCamera()
{
	return camera_;
}

void View::drawEyeshot(const LocationData & dat)
{
	double toRadians = M_PI/180;
	
	int x1 = static_cast<int>(dat.coordinates_.x);
	int y1 = static_cast<int>(dat.coordinates_.y);

	int range = static_cast<int>(dat.lookingRad / 2);

	double angleA = (dat.lookingAngle - range)*toRadians; 
	double angleB = (dat.lookingAngle + range)*toRadians;;

	int x2 = static_cast<int> (x1 + dat.sightLen_*std::cos(angleA));
	int y2 = static_cast<int>(y1 + dat.sightLen_*std::sin(angleA));

	int x3 = static_cast<int>(x1 + dat.sightLen_*std::cos(angleB));
	int y3 = static_cast<int>(y1 + dat.sightLen_*std::sin(angleB));

	SDL_Color col{ 0xff, 0, 0, 0 };
	
	for (double angle = angleA; angle <= angleB; angle+=(toRadians/2))
	{
		getGraphics().drawPoint(camera_,
			static_cast<int>(x1 + dat.sightLen_*std::cos(angle)),
			static_cast<int>(y1 + dat.sightLen_*std::sin(angle)),
			col);
		getGraphics().drawPoint(camera_,
			static_cast<int>(x1 + 1 + dat.sightLen_*std::cos(angle)),
			static_cast<int>(y1 + 1 + dat.sightLen_*std::sin(angle)),
			col);
	}

	getGraphics().drawLine(camera_, x1, y1, x2, y2, col);
	getGraphics().drawLine(camera_, x1, y1, x3, y3, col);
}

void View::drawHelp()
{
	/*Calculating position of help frame on the screen.*/
	SDL_Rect frame{ camera_.x + (SCREEN_WIDTH - HELP_FRAME_WIDTH) / (2 * getGraphics().getScale()),
					camera_.y + 30/getGraphics().getScale(),
					HELP_FRAME_WIDTH, 
					HELP_LINE_HEIGHT*HELP.size() + 2*MARGIN_SIZE };

	getGraphics().drawFrame(camera_, frame, getGraphics().get(Graphics::FRAME_BACKGROUND));
	for (unsigned i = 0; i < HELP.size(); ++i)
	{
		getGraphics().renderText(camera_, getGraphics().get(Graphics::HELP_FONT), HELP[i],
			getGraphics().getScaledPosition(frame.x, camera_.x) + MARGIN_SIZE,
			getGraphics().getScaledPosition(frame.y, camera_.y) + MARGIN_SIZE + i* HELP_LINE_HEIGHT, SDL_Color{ 0, 0, 0, 0 });
	}
}

void View::changeScale(double delta)
{
	double newScale = getGraphics().getScale() + delta;
	if ((newScale < 0.3 || newScale>2)||
		(camera_.x + camera_.w / newScale >= Parameters::mapWidth)||
		(camera_.y + camera_.h /newScale >= Parameters::mapHeight))
		return;
	getGraphics().setScale(newScale);

}

double View::getScale() const
{
	return getGraphics().getScale();
}