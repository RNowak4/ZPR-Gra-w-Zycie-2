#include "SdlHelper.h"

void SdlHelper::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window_ = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
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