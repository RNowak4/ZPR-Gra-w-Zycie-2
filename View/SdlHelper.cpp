#include "SdlHelper.h"

bool SdlHelper::init()
{
	return true;
}

bool SdlHelper::loadMedia()
{
	return true;
}

void SdlHelper::close()
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	renderer_ = NULL;
	window_ = NULL;
	SDL_Quit();
}