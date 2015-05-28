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

class View;
class Model;

class Controller
{
public:
	void getModel(Model*);
	void getView(View *);
	Controller();

	/**
	*This funtion takes SDL_Event captured by View, and takes proper action depending on the event.
	*/
	void handleEvent(const SDL_Event&);
	void handleEvent(const TimeEvent&);
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