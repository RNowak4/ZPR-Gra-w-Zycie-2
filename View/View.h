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
#include <vector>

class Controller;


class View
{
public:
	View();

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	static const int FPS;
	static const double FRAME_TIME;
	static const int FONT_HEIGHT;
	static const int FRAMES_COUNT_TO_UPDATE;
	static const std::vector<std::string> HELP;

	/**
	Draw creature on the screen.

	@param LocationData informations about creature location, looking angle, looking radius	and type of creature.
	*/
	void drawCreature(const LocationData &);

	/**
	Get controller for view.

	@param controller pointer to the Controller module of the program.
	*/
	void getController(Controller* controller);

	/**@return Reference to SDL_Rect struct which is representing location and size of camera.*/
	const SDL_Rect& getCamera();

	/**
	Draw specific information about creature on the screen, including all important parameters and view range.

	@param data std::pair containing of information about creature. 
	*/
	void drawCreatureInfo(const std::pair<const LocationData*, const AnimalData*>& data);

	/**Draw background, grass, relative to camera position.*/
	void drawBackground();

	/**Draw window with help information for user, on game screen.*/
	void drawHelp();

	/**
	Move the visible region of the map.

	@param x how many pixels camera has to move horizontally (right if positive, left if negative).
	@param y how many pixels camera has to move vertically (down if positive, up if negative).
	*/
	void moveCamera(int x, int y);

	void changeScale(double delta);

	double getScale() const;

	/**This method executes the main program loop.*/
	void run();

	/**End the main program loop.*/
	void quit();

private:
	
	void drawEyeshot(const LocationData &);

	Controller* controller_;
	SDL_Event event_;
	SDL_Rect camera_;
	bool quit_;
	
};

#endif //VIEW_H
