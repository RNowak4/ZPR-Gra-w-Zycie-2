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
#include <memory>
#include "../Exception/GameOfLifeException.h"
class Assets;
class SdlHelper
{
public:
	/**
	*Initialize SDL, create window  and renderer.
	*@return true if succes, otherwise false
	*/
	void init();

	/**
	*Unload libraries, clean up all initialized subsystems.
	*/
	void close();

	/**
	*Set size of the simulation screen.
	*@param width how wide will window be in pixels.
	*@param height height of window in pixels.
	*/
	void setWindowSize(int width,int height);
	void setWindowTitle(const std::string & title);
	
	/**
	*Draw image on the screen.
	*@param camera		 SDL_Rect object which is enclosing area of the screen.
	*@param tex			 texture that has to be drawed.
	*@param x			 horizontal position on the screen.
	*@param y			 vertical position on the screen.
	*@param centered	 if true, the x and y cordinates are in the center of the image.
	*@param angle		 the angle of image
	*@param alpha		 transparency of image, if 255, the image is not transparent at all. 
	*					 Lesser  is the  value, the more transparent is image.
	*/
	void draw(const SDL_Rect& camera, std::shared_ptr<SDL_Texture> tex, int x, int y, bool centered = false, double angle = 0, Uint8 alpha = 255);

	/**
	*Draw text on the screen.
	*@param camera		 SDL_Rect object which is enclosing area of the screen.
	*@param font		 font used to print text.
	*@param message		 message that has to be printed.
	*@param x			 horizontal position on the screen.
	*@param y			 vertical position on the screen.
	*@param color		 color of the font.
	*/
	void renderText(const SDL_Rect& camera, std::shared_ptr<TTF_Font> font, const std::string& message, int x, int y, const SDL_Color& color);

	/**
	*Draw frame in shape of rectangle on the screen filled with given texture.  
	*@param camera		 when is not null, rectangle will be in position relative to thic camera position.
	*@param rectangle    rectangle meaning area we want to cover with frame.
	*@param filling		 texture, which is intender to cover the area of the frame.
	*/
	void drawFrame(const SDL_Rect& camera, SDL_Rect rectangle, std::shared_ptr<SDL_Texture> filling);

	/**
	*Draw line on the screen. 
	*@param camera SDL_Rect object which is enclosing area of the screen.
	*@param x1 horizontal position of beginning of the line on the screen.
	*@param y1 vertical position of beginning of the line on the screen.
	*@param x2 horizontal position of ending of the line on the screen.
	*@param y2 vertical position of ending of the line on the screen.
	*@param color color of the line.
	*/
	void drawLine(const SDL_Rect& camera, int x1, int y1, int x2, int y2, const SDL_Color& color);

	/**
	*Draw point on the screen.
	*@param camera		SDL_Rect object which is enclosing area of the screen.
	*@param x			horizontal position of point on the screen.
	*@param y			vertical position of point on the screen.
	*@param color		color of the point.
	*/
	void drawPoint(const SDL_Rect& camera, int x, int y, const SDL_Color& color);

	/**
	*Clean the screen, remove anything drawn on it .
	*/
	void clearScreen();

	/**
	*Show everything drawed by renderer on the screen.
	*/
	void renderScreen();

private:
	/**
	*Checks if one of the rectangles overlaps another.
	*@param r1 reference to first rectangle.
	*@param r2 reference to second rectangle.
	*/
	bool overlap(const SDL_Rect& r1,const SDL_Rect& r2);


	std::shared_ptr<SDL_Window> window_;
	std::shared_ptr<SDL_Renderer> renderer_;
	friend class Assets;
};

#endif //SDLHELPER_H
