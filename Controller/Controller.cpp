#include "Controller.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include <iostream>
#include "../Model/Constants.h"
#include "../Model/Parameters.h"
#include "../Exception/GameOfLifeException.h"

Controller::Controller()
{
	gamePaused_ = false;
	drawHelp_ = false;
}

void Controller::getModel(Model* m)
{
	model_ = m;
	loadSettings("settings.txt");

	Parameters::adultWidth = 40;
	Parameters::adultHeigth = 40;

	//Constants::adultWidth  = 40; //Chwilowo
	//Constants::adultHeigth = 40; //Chwilowo
	

	
}
void Controller::getView(View* v)
{
	view_ = v;
}

void Controller::handleEvent(const SDL_Event & e)
{
	int step = 15;
	SDL_Rect camera = view_->getCamera();
	switch (e.type)
	{
	case SDL_QUIT:
		view_->quit();
		break;

	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			if (camera.x - step >= 0)
				view_->moveCamera(-step, 0);
			break;
		case SDLK_RIGHT:
			if (camera.x + camera.w + step <= Constants::mapWidth)
				view_->moveCamera(step, 0);
			break;
		case SDLK_UP:
			if (camera.y - step >= 0)
				view_->moveCamera(0, -step);
			break;
		case SDLK_DOWN:
			if (camera.y + camera.h + step <= Constants::mapHeight)
				view_->moveCamera(0, step);
			break;
		case SDLK_p:
			gamePaused_ = !gamePaused_;
			break;
		case SDLK_h:
			drawHelp_ = !drawHelp_;
			break;
		case SDLK_ESCAPE:
			view_->quit();
			break;
		}
		break;
	case SDL_MOUSEBUTTONDOWN :
		model_->switchAnimalRegister(e.button.x + camera.x, e.button.y + camera.y);
		break;
	}
}

void Controller::handleEvent(const TimeEvent&)
{
	if (gamePaused_ == false)
	{
		model_->updateAnimalsStatuses();
	}
}

void Controller::update()
{
	if (gamePaused_ == false)
	{
		model_->updateAnimalsPosition();
	}

	

	auto creatures = model_->getAnimalsData();
	for (auto i : *creatures)
	{
		view_->drawCreature( * i.first );
	}
	for (auto i : *creatures)
	{
		if (i.second != nullptr)
		{
			view_->drawCreatureInfo(i);
		}
	}

	if (drawHelp_ == true)
	{
		view_->drawHelp();
	}
}

void Controller::loadSettings(const std::string& path )
{
	std::ifstream file;
	file.open(path);
	if (!file.good())
		return;
	std::stringstream ss;
	std::string command;

	while (std::getline(file, command))
	{
		processCommand(command);
	}
}

void Controller::processCommand(const std::string & command)
{
	std::stringstream ss(command);
	std::string what;
	ss >> what;

	if (what == "MAP_WIDTH")
	{
		ss >> Parameters::mapWidth;
	}
	else if (what == "MAP_HEIGHT")
	{
		ss >> Parameters::mapHeight;
	}
	else if (what == "CARNIVORE")
	{
		int x, y;
		ss >> x >> y;
		model_->createCarnivore(x,y);
	}
	else if (what == "HERBIVORE")
	{
		int x, y;
		ss >> x >> y;
		model_->createHerbivore(x, y);
	}

}
