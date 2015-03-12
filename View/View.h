/**
* @file View.h
* @brief Class that is responsible for drawing things on the screen.
*
* @author Damian Mazurkiewicz
*
*/
#ifndef VIEW
#define VIEW


class View
{
public:
	View() : mySdl_(), controller_(nullptr) {}
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
	SDLHelper mySDL_;	///< Class that manages the SLD library and provides an useful interface for it.
	Controller* controller_;

};

#endif //VIEW