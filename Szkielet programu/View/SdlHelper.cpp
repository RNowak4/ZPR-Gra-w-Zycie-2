#include "SdlHelper.h"

void SdlHelper::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window_ = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
	IMG_Init(IMG_INIT_PNG); ///Loading dynamic libraries to use  PNG format.

	
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
		if (tmp.y  >= camera->y+camera->h)
		{
			return;
		}

		if (tmp.y + tmp.h <= camera->y)
		{
			return;
		}

		if (tmp.x + tmp.w <= camera->x)
		{
			return;
		}

		if (tmp.x >= camera->x+camera->w)
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