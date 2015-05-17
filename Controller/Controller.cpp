#include "Controller.h"
#include "../View/View.h"
#include "../Model/Model.h"
#include <iostream>


void Controller::getModel(Model* m)
{
	model_ = m;

	//Code for testing purposes (rendering creatures).
	for (int i = 60; i < 640; i += 90)
		for (int j = 60; j < 480; j += 90)
			m->createCarnivore(i, j);
}
void Controller::getView(View* v)
{
	view_ = v;
}

void Controller::handleEvent(SDL_Event* e)
{
	int step = 15;
	switch (e->type)
	{
	case SDL_QUIT:
		view_->quit();
		std::cout << "Koniec." << std::endl;
		break;
	
	case SDL_KEYDOWN:	
		SDL_Rect camera = view_->getCamera();
		switch (e->key.keysym.sym)
		{
		case SDLK_LEFT:
			if (camera.x-step >= 0)
				view_->moveCamera(-step,0);
			break;
		case SDLK_RIGHT:
			view_->moveCamera(step, 0);
			break;
		case SDLK_UP:
			if (camera.y-step>=0)
				view_->moveCamera(0 ,-step);
			break;
		case SDLK_DOWN:
			view_->moveCamera(0, step);
			break;
		}
		break;
	}
}

void Controller::update()
{
	
	model_->updateAnimalsPosition();
	auto creatures = model_->getAnimalsData();

	for (auto i : creatures)
	{
		view_->drawCreature( * i.first );
		if (i.second != nullptr)
		{
			view_->drawCreatureInfo(i.first->coordinates_.x, i.first->coordinates_.y, i.second);
		}
	}
	
		
}
