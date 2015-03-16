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

class View;
class Model;

class Controller
{
public:
	void getModel(Model*);
	void getView(View *);

	/**
	*This funtion takes SDL_Event captured by View, and takes proper action depending on the event.
	*/
	void handleEvent(SDL_Event*);
private:
	Model* model_;
	View* view_;
	
};
#endif  //CONTROLLER_H