/**
File contains Controller class.
@author Damian Mazurkiewicz
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

	const static int CAMERA_STEP; /**<Movement (in pixels) of camera in one frame.*/
	const static double SCALE_DELTA; /**<Scale change in one frame. */
	const static std::string SETTINGS_PATH; /**< Where is settings file.*/

	/**
	Initialize Controller obiect, load settings from file.
	@param model pointer to object containing logic of the simulation.
	@param view  pointer to object capable of displaying current state of simulation on the screen.
	*/
	Controller(Model* model, View* view);

	/**
	This funtion takes SDL_Event captured by View, and takes proper action depending on the event.
	@param what Event sent from View, it describes current action of simulation watcher.
	*/
	void handleEvent(const SDL_Event& what);


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
	Load settings,simulation details from file.
	@param path path to the file with settings.
	*/
	void loadSettings(const std::string& path);	

	/**Process one line from settings file, set configuration of simulation basing on it. */
	void processCommand(const std::string&);

	/**Change the position of the camera in View basing on values of camera movements stored in Controller.*/
	void moveCamera();

	Model* model_;
	View* view_;
};
#endif  //CONTROLLER_H