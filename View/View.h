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
#include <cmath>

class Controller;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int MAP_WIDTH = 1000;
const int MAP_HEIGHT = 1000;
const int FPS = 50;
const double FRAME_TIME = 1/(double)FPS;
const int FONT_HEIGHT = 10;


class View
{
public:
	View();

	/**
	*Draw creature on the screen.
	*@param LocationData informations about creature location, looking angle, looking radius
	*		and type of creature.
	*/
	void drawCreature(const LocationData &);
	/**
	*Get controller for view.
	*@param controller pointer to the Controller module of the program.
	*/
	void getController(Controller* controller);
	const SDL_Rect & getCamera();
	void drawCreatureInfo(const std::pair<const LocationData*, const AnimalData*>&);
	void drawBackground();
	/**
	*Move the visible region of the map.
	*@param x how many pixels camera has to move horizontally (right if positive, left if negative).
	*@param y how many pixels camera has to move vertically (down if positive, up if negative).
	*/
	void moveCamera(int x, int y);
	/**
	*This method executes the main program loop.
	*@return void
	*/
	void run();
	/**
	*End main program loop..
	*/
	void quit();
private:
	void drawEyeshot(const LocationData &);
	void drawEyeshotCone(const LocationData &);

	SdlHelper mySDL_;
	Controller* controller_;
	SDL_Event event_;
	SDL_Rect camera_;
	bool quit_;
	
};

#endif //VIEW_H
