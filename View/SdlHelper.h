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
#include <SDL_image.h>
#else
//define it for a Unix machine
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#endif
#include <iostream>
#include <vector>
class Assets;
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
	void loadMedia();
	void close();

	void setWindowSize(int width,int height);
	void setWindowTitle(const std::string & title);
	
	void draw(SDL_Rect* camera, SDL_Texture* tex, int x, int y, bool centered = false, double angle = 0, Uint8 alpha = 255);

	void clearScreen();
	void renderScreen();

private:
	SDL_Window *window_;
	SDL_Renderer *renderer_;
	friend class Assets;

};

#endif SDLHELPER_H