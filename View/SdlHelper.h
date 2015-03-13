/**
* @file SdlHelper.h
* @brief Class that manages the SLD library and provides an useful interface for it.
*
* @author Damian Mazurkiewicz
*/

#ifndef SDLHELPER_H
#define SDLHELPER_H

#include <SDL.h>

class SdlHelper
{
public:
	/**
	*@function init
	*@brief Initialize SDL, create window  and renderer
	*@return true if succes, otherwise false
	*/
	bool init();
	/**
	*@function loadMedia
	*@brief loads all textures  and fonts
	*@return true if succes, otherwise false
	*/
	bool loadMedia();

	void close();
	
private:
	SDL_Window * window_;
	SDL_Renderer * renderer_;
};

#endif SDLHELPER_H