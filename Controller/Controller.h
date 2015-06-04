/**
File contains Controller class.
* @author Damian Mazurkiewicz
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#ifdef _WIN32
#include <SDL.h>
#else
//define it for a Unix machine
#include <SDL2/SDL.h>
#endif
#include "../View/TimeEvent.h"
#include <fstream>
#include <sstream>
#include <memory>

class View;
class Model;

/**
Class takes input from View module. Does proper action depending on it. 
It can update Model basing on events from View. It "tells" View what to
draw.
*/
class Controller
{
public:
	void getModel(Model* model);
	void getView(View* view);
	Controller();
	/**
	This funtion takes SDL_Event captured by View, and takes proper action depending on the event.
	*/
	void handleEvent(const SDL_Event&);

	/**
	This function takes TimeEvent, which notifies Controller about passing the required time to update
	creatures parameters.
	*/
	void handleEvent(const TimeEvent&);

	/**Update Model and refresh View.*/
	void update();

private:
	bool gamePaused_; ///<When game is paused, model is not updated.
	bool drawHelp_;	///<When true, frame with help information is shown on the screen.
	int verticalCameraMovement_;
	int horizontalCameraMovement_;
	double scaleDelta_;
	enum {SLOWER,FIXED,FASTER} speedModifier_;

	/**
	Load settings and simulation details from file.

	@param path path to the file with settings.
	*/
	void loadSettings(const std::string& path);	

	/**Process one line from settings file, set configuration of Controller basing on it. */
	void processCommand(const std::string&);

	void moveCamera();

	Model* model_;
	View* view_;
};
#endif  //CONTROLLER_H