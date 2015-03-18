#include "Controller.h"
#include "View/View.h"
#include <iostream>


void Controller::getModel(Model* m)
{
	model_ = m;
}
void Controller::getView(View* v)
{
	view_ = v;
}

void Controller::handleEvent(SDL_Event* e)
{
	switch (e->type)
	{
	case SDL_QUIT:
		view_->quit();
		std::cout << "no elo." << std::endl;
		break;
	
	case SDL_KEYDOWN:	
		switch (e->key.keysym.sym)
		{
		case SDLK_LEFT:
			view_->moveCamera(-10,0);
			break;
		case SDLK_RIGHT:
			view_->moveCamera(10, 0);
			break;
		case SDLK_UP:
			view_->moveCamera(0 ,-10);
			break;
		case SDLK_DOWN:
			view_->moveCamera(0, 10);
			break;
		}
		break;
	}
}

void Controller::update(boost::timer& t)
{
	if (t.elapsed() >= 1)
	{
		std::cout << "ciekawostka : minela sekunda!" << std::endl;
		t.restart();
	}
}