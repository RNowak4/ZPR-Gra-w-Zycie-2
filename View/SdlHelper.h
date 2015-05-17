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
#include <SDL_ttf.h>
#else
//define it for a Unix machine
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
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
	
	/**
	*Draw image on the screen.
	*@param camera		- SDL_Rect object which is enclosing area of the screen.
	*@param tex			 - texture that has to be drawed.
	*@param x,y			- position on the screen
	*@param centered	- if true, the x and y cordinates are in the center of the image.
	*@param angle		- the angle of image
	*@param alpha		- transparency of image, if 255, the image is not transparent at all. The lesser value, the more transparent is image.
	*/
	void draw(SDL_Rect* camera, SDL_Texture* tex, int x, int y, bool centered = false, double angle = 0, Uint8 alpha = 255);

	/**
	*Draw text on the screen.
	*@param camera		- SDL_Rect object which is enclosing area of the screen.
	*@param font		- font used to print text.
	*@param message		- message that has to be printed.
	*@param x,y			- position on the screen.
	*@param color		- color of the font.
	*/
	void renderText(SDL_Rect* camera, TTF_Font* font, const std::string message, int x, int y, SDL_Color color);

	/**
	*Draw rectangle on the screen.
	*@param camera		- when is not null, rectangle will be in position relative to thic camera position.
	*@param rectangle	- rectangle we want to draw.
	*@param color		- it determines color and alpha of rectamgle.
	*/
	void drawFrame(SDL_Rect* camera, SDL_Rect* rectangle, SDL_Texture* filling);

	void clearScreen();
	void renderScreen();

private:
	bool overlap(const SDL_Rect& r1,const SDL_Rect& r2);
	SDL_Window *window_;
	SDL_Renderer *renderer_;
	friend class Assets;

};

#endif //SDLHELPER_H
