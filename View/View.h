/**
View class.
@author Damian Mazurkiewicz
*/

#ifndef VIEW_H
#define VIEW_H

#include "Graphics.h"
#include "../Model/Model.h"
#include <chrono>
#include <cmath>
#include <vector>

class Controller;

/**
Class that is responsible for providing visualization of the simulation on the screen.
*/
class View
{
public:
	
	static const int SCREEN_WIDTH;	/**< Width of the simulation screen. */
	static const int SCREEN_HEIGHT; /**< Height of the simulation screen. */
	static const int FPS;			/**< How many frames per second will be shown. */
	static const double FRAME_TIME; /**< How long does one frame lasts. */

	static const int DEFAULT_LINE_HEIGHT;
	static const int HELP_LINE_HEIGHT;
	static const int MARGIN_SIZE;
	static const int DESCRIPTION_FRAME_WIDTH;
	static const int HELP_FRAME_WIDTH;

	static const std::vector<std::string> HELP; /**< Contents of a help window. */

	/**Initalize fields of View object.*/
	View();

	/**
	Draw creature on the screen.
	@param data informations about creature location, looking angle, looking radius	and type of creature.
	*/
	void drawCreature(const LocationData& data);

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

	/**
	Modify zoom of the camera.
	@delta delta if positive, zoom in, otherwise, zoom out.
	*/
	void changeScale(double delta);

	double getScale() const;

	/**Start simulation.*/
	void run(Controller* controller);

	
	/**End the main program loop.*/
	void quit();

private:
	/**Draw visual range of creature.
	@param data location, looking angle, sight length of creature.
	*/
	void drawEyeshot(const LocationData & data);

	Controller* controller_;
	SDL_Event event_;
	SDL_Rect camera_;
	bool quit_;
};

#endif //VIEW_H
