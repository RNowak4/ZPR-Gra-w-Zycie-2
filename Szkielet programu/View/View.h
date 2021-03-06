/**
* @file View.h
* @brief Class that is responsible for drawing things on the screen.
*
* @author Damian Mazurkiewicz
*/
#ifndef VIEW_H
#define VIEW_H

#include "SdlHelper.h"
#include "Assets.h"
#include "../Model/Model.h"
#include <chrono>

class Controller;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int MAP_WIDTH = 1000;
const int MAP_HEIGHT = 1000;
const int FPS = 50;
const double FRAME_TIME = 1/(double)FPS;


class View
{
public:
	View();
	void drawCreature(const Animal::LocationData &);
	void getController(Controller*);
	const SDL_Rect & getCamera();
	void drawCreatureInfo();
	void drawBackground();
	void moveCamera(int x, int y);
	/**
	*This method executes the main program loop.
	*@return void
	*/
	void run();
	void quit();
private:
	SdlHelper mySDL_;
	Controller* controller_;
	SDL_Event event_;
	SDL_Rect camera_;
	bool quit_;
	
};

#endif //VIEW_H
