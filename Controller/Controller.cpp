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
	vericalCameraMovement_=horizontalCameraMovement_=0;
}

void Controller::getModel(Model* model)
{
	model_ = model;
	loadSettings("settings.txt");

	Parameters::adultWidth = 40;
	Parameters::adultHeigth = 40;

}
void Controller::getView(View* view)
{
	view_ = view;
}

void Controller::handleEvent(const SDL_Event & e)
{
	int step = 20;
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
			horizontalCameraMovement_ = -step;
			break;
		case SDLK_RIGHT:
			horizontalCameraMovement_ = step;
			break;
		case SDLK_UP:
			vericalCameraMovement_ = -step;
			break;
		case SDLK_DOWN:
			vericalCameraMovement_ = step;
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
	case SDL_KEYUP:
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			horizontalCameraMovement_ = 0;
			break;
		case SDLK_RIGHT:
			horizontalCameraMovement_ = 0;
			break;
		case SDLK_UP:
			vericalCameraMovement_ = 0;
			break;
		case SDLK_DOWN:
			vericalCameraMovement_ = 0;
			break;
		}
		break;
	}
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
	moveCamera();
	

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
		try
		{
			processCommand(command);
		}
		catch (invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
			throw LoadingSettingsExcepion();
		}
		catch (out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
			throw LoadingSettingsExcepion();
		}

	}
}

void Controller::processCommand(const std::string & command)
{
	std::stringstream ss(command);
	std::string what;
	std::string arg;
	ss >> what;

	if (!ss.good())
		return;

	if (what == "MAP_WIDTH")
	{
		ss >> arg; Parameters::mapWidth = std::stoi(arg);
	}
	else if (what == "MAP_HEIGHT")
	{
		ss >> arg; Parameters::mapHeight = std::stoi(arg);
	}
	else if (what == "CARNIVORE")
	{
		ss >> arg; int x = std::stoi(arg);
		ss >> arg; int y = std::stoi(arg);
		model_->createCarnivore(x,y);
	}
	else if (what == "HERBIVORE")
	{
		ss >> arg; int x = std::stoi(arg);
		ss >> arg; int y = std::stoi(arg);
		model_->createHerbivore(x, y);
	}
	

}

void Controller::moveCamera()
{
	SDL_Rect camera = view_->getCamera();

	if (camera.x + horizontalCameraMovement_ >= 0 &&
		camera.x + camera.w + horizontalCameraMovement_ <= Constants::mapWidth &&
		camera.y + vericalCameraMovement_ >= 0 &&
		camera.y + camera.h + vericalCameraMovement_ <= Constants::mapHeight)
				view_->moveCamera(horizontalCameraMovement_, vericalCameraMovement_);
			
}