/**
* @file View.h
* @brief Class that is responsible for drawing things on the screen.
*
* @author Damian Mazurkiewicz
*/
#ifndef VIEW_H
#define VIEW_H

#include "SdlHelper.h"
class Controller;

class View
{
public:
	View() : mySDL_(nullptr), controller_(nullptr) {}
	void drawCreature();
	void getController(Controller*); 
	void drawCreatureInfo();
	void drawBackground();
	/**
	*This method executes the main program loop.
	*@return void
	*/
	void run();
private:
	SdlHelper* mySDL_;	
	Controller* controller_;

};

#endif //VIEW_H