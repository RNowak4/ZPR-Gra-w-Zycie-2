/**
* @file Controller.h
* @brief Controller class, handles input from user and tells View what to draw.
*
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
	bool gamePaused_;
	bool drawHelp_;
	void loadSettings(const std::string&);
	void processCommand(const std::string&);
	Model* model_;
	View* view_;
};
#endif  //CONTROLLER_H