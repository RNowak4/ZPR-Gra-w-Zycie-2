/**
@file Controller.cpp
@brief Implementation of Controller methods.
@author Damian Mazurkiewicz
*/
#include "Controller.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include <iostream>
#include "../Model/Constants.h"
#include "../Model/Parameters.h"
#include "../Exception/GameOfLifeException.h"
#include <random>

const int Controller::CAMERA_STEP = 20;
const double Controller::SCALE_DELTA = 0.02;
const std::string Controller::SETTINGS_PATH = "settings.txt";

Controller::Controller(Model* model, View* view) : 
gamePaused_(false),
drawHelp_(false),
verticalCameraMovement_(0),
horizontalCameraMovement_(0),
speedModifier_(FIXED),
scaleDelta_(0),
model_(model),
view_(view)
{
	if (model_ == nullptr || view_ == nullptr)
	{
		throw InitalizingControllerException();
	}
	Parameters::mapHeight = Parameters::mapWidth = 0;
	loadSettings(SETTINGS_PATH);
	if (Parameters::mapWidth == 0 || Parameters::mapHeight == 0)
	{
		throw LoadingSettingsExcepion();
	}	
	Parameters::adultHeigth = Parameters::adultWidth = 40;
	Parameters::youngHeigth = Parameters::youngWidth = 30;
}



void Controller::handleEvent(const SDL_Event & e)
{
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
			horizontalCameraMovement_ = -CAMERA_STEP;
			break;
		case SDLK_RIGHT:
			horizontalCameraMovement_ = CAMERA_STEP;
			break;
		case SDLK_UP:
			verticalCameraMovement_ = -CAMERA_STEP;
			break;
		case SDLK_DOWN:
			verticalCameraMovement_ = CAMERA_STEP;
			break;
		case SDLK_w:
			scaleDelta_ = SCALE_DELTA*view_->getScale();
			break;
		case SDLK_s:
			scaleDelta_ = -SCALE_DELTA*view_->getScale();
			break;
		case SDLK_a:
			speedModifier_ = SLOWER;
			break;
		case SDLK_d:
			speedModifier_ = FASTER;
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
		case SDLK_RIGHT:
			horizontalCameraMovement_ = 0;
			break;
		case SDLK_UP:
		case SDLK_DOWN:
			verticalCameraMovement_ = 0;
			break;
		case SDLK_w:
		case SDLK_s:
			scaleDelta_ = 0;
			break;
		case SDLK_a:
		case SDLK_d:
			speedModifier_ = FIXED;
			break;
		}
		break;
	}
	case SDL_MOUSEBUTTONDOWN :
		model_->switchAnimalRegister(e.button.x/view_->getScale() + camera.x, e.button.y/view_->getScale() + camera.y);
		break;
	}
}



void Controller::update()
{
	/*Setting view, simulation options.*/
	if (speedModifier_ != FIXED)
	{
		if (speedModifier_ == FASTER)
		{
			model_->fasterSimulation();
		}
		else
		{
			model_->slowerSimulation();
		}
	}
	view_->changeScale(scaleDelta_);
	moveCamera();

	/*Updating Model.*/
	if (gamePaused_ == false)
	{
			model_->updateAnimalsStatuses();
	}
	
	/*Refreshing View.*/
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
	if (!file.is_open())
		return;
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
	file.close();
}

void Controller::processCommand(const std::string & command)
{
	std::stringstream ss(command);
	std::string what;
	std::string arg;
	ss >> what;

	if (!ss.good())
		return;

	if (what == "MAP_WIDTH" && Parameters::mapWidth==0)
	{
		ss >> arg;
		Parameters::mapWidth = std::stoi(arg);
		if (Parameters::mapWidth  < View::SCREEN_WIDTH)
			throw LoadingSettingsExcepion();
	
	}
	else if (what == "MAP_HEIGHT" && Parameters::mapHeight==0)
	{
		ss >> arg; 
		Parameters::mapHeight = std::stoi(arg);
		if (Parameters::mapHeight  < View::SCREEN_HEIGHT)
			throw LoadingSettingsExcepion();
	}
	else if (Parameters::mapWidth == 0 || Parameters::mapHeight == 0)
	{
		throw LoadingSettingsExcepion();
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
	else if (what == "THROW_HERBIVORES" || what == "THROW_CARNIVORES")
	{
		ss >> arg; int number = std::stoi(arg);
		int x;
		int y;
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> Hdistribution(Parameters::adultWidth, Parameters::mapWidth - Parameters::adultWidth);
		std::uniform_int_distribution<int> Vdistribution(Parameters::adultHeigth, Parameters::mapHeight - Parameters::adultWidth);

		for (int i = 0; i < number; ++i)
		{
			x = Hdistribution(generator);
			y = Vdistribution(generator);
			if (what == "THROW_HERBIVORES")
			{
				model_->createHerbivore(x, y);
			}
			else
			{
				model_->createCarnivore(x, y);
			}
		}
	}
}

void Controller::moveCamera()
{
	SDL_Rect camera = view_->getCamera();
	if ((camera.x + horizontalCameraMovement_ >= 0) &&
		((camera.x + camera.w / view_->getScale() + horizontalCameraMovement_ <= Parameters::mapWidth) ) &&
		(camera.y + verticalCameraMovement_ >= 0 ) &&
		((camera.y + camera.h / view_->getScale() + verticalCameraMovement_ <= Parameters::mapHeight)))
				view_->moveCamera(horizontalCameraMovement_, verticalCameraMovement_);
			
}
