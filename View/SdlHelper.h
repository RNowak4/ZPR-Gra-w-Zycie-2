/**
* @file SdlHelper.h
* @brief Class that manages the SLD library and provides an useful interface for it.
*
* @author Damian Mazurkiewicz
*/

#ifndef SDLHELPER_H
#define SDLHELPER_H

#ifdef _WIN32
#include <SDL.h>
#else
//define it for a Unix machine
#include <SDL2/SDL.h>
#endif



class SdlHelper
{
public:
	/**
	*@function init
	*@brief Initialize SDL, create window  and renderer
	*@return true if succes, otherwise false
	*/
	void init();
	/**
	*@function loadMedia
	*@brief loads all textures  and fonts
	*@return true if succes, otherwise false
	*/
	bool loadMedia();

	void close();
	SDL_Renderer * renderer_;

private:
	SDL_Window * window_;

};

#endif SDLHELPER_H