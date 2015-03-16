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
	if (e->type == SDL_QUIT)
	{
		view_->quit();
		std::cout << "no elo." << std::endl;
	}
}

void Controller::update(boost::timer& t)
{
	if (t.elapsed() > 1)
	{
		std::cout << "ciekawostka : minela sekunda!" << std::endl;
		t.restart();
	}
}