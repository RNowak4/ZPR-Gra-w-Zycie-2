#include "SdlHelper.h"
#include "Assets.h"

void SdlHelper::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window_ = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
	IMG_Init(IMG_INIT_PNG); ///Loading dynamic libraries to use  PNG format.
	TTF_Init();

	
	return;
}

void SdlHelper::loadMedia()
{
	
}

void SdlHelper::close()
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	renderer_ = NULL;
	window_ = NULL;

	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

}

void SdlHelper::clearScreen()
{
	SDL_RenderClear(renderer_);
}
void SdlHelper::renderScreen()
{
	SDL_RenderPresent(renderer_);
}
void SdlHelper::setWindowSize(int width, int height)
{
	SDL_SetWindowSize(window_, width, height);
}
void SdlHelper::setWindowTitle(const std::string & title)
{
	SDL_SetWindowTitle(window_, title.c_str());
}

void SdlHelper::draw(SDL_Rect* camera, SDL_Texture* tex, int x, int y, bool centered, double angle, Uint8 alpha)
{
	SDL_Rect tmp; tmp.x = x; tmp.y = y;
	SDL_QueryTexture(tex, nullptr, nullptr, &tmp.w, &tmp.h);

	/*
	*When centered == true we see the coordinates x,y as the center of image instead left-top corner.
	*/
	if (centered == true)
	{
		tmp.x -= tmp.w / 2;
		tmp.y -= tmp.h / 2;
	}

	/*
	*When we are using camera, we need to check if the object which we want to draw is seen from camera.
	*When it is, we need to changee the coordinates of the object which we want to draw to make them 
	*relative to the camera position.
	*/
	if (camera!=nullptr)
	{
		if (!overlap(tmp, *camera))
		{
			return;
		}
		tmp.x -= camera->x;
		tmp.y -= camera->y;
	}
	SDL_SetTextureAlphaMod(tex,alpha); //Setting alpha for texture.

	SDL_RenderCopyEx(renderer_, tex, NULL, &tmp, angle, nullptr, SDL_FLIP_NONE);

	SDL_SetTextureAlphaMod(tex, 255);  //After drawing we bring texture back to normal state ( not transparent ).
}

void SdlHelper::renderText(SDL_Rect* camera, TTF_Font* font, const std::string message, int x, int y, SDL_Color color)
{

	SDL_Surface *surface = TTF_RenderText_Blended(font, message.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_, surface);
	draw(camera, texture, x, y);

	//Clean up the surface and font
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);

}

void SdlHelper::drawFrame(SDL_Rect* camera, SDL_Rect* rectangle, SDL_Texture* filling)
{
	if (camera != nullptr)
	{
		if (!overlap(*rectangle, *camera))
		{
			return;
		}
		rectangle->x -= camera->x;
		rectangle->y -= camera->y;
	}
	SDL_SetTextureAlphaMod(filling, 0xa0); //Setting alpha for texture.
	SDL_RenderCopy(renderer_,filling, NULL, rectangle);
	SDL_SetTextureAlphaMod(filling, 0xff);  //After drawing we bring texture back to normal state ( not transparent ).
	SDL_SetRenderDrawColor(renderer_, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderDrawRect(renderer_, rectangle);

	

}

bool SdlHelper::overlap(const SDL_Rect& r1, const SDL_Rect& r2)
{
	if (r1.y >= r2.y + r2.h ||
		r1.y + r1.h <= r2.y ||
		r1.x + r1.w <= r2.x ||
		r1.x >= r2.x + r2.w )
		{
		return false;
		}
	return true;
}

void SdlHelper::drawLine(SDL_Rect* camera, int x1, int y1, int x2, int y2, const SDL_Color & color)
{
	if (camera != nullptr)
	{
		x1 -= camera->x; 
		x2 -= camera->x;
		y1 -= camera->y;
		y2 -= camera->y;
	}
	SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}