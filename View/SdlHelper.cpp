#include "SdlHelper.h"
#include "Assets.h"

void SdlHelper::init()
{
	if (SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		throw InitializingSdlHelperException();
	}

	if (IMG_Init(IMG_INIT_PNG) == 0) ///Loading dynamic libraries to use  PNG format.
	{
		throw InitializingSdlHelperException();
	}
	if (TTF_Init() != 0)
	{
		throw InitializingSdlHelperException();
	}


	window_ = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Game of Life", 30, 30, 640, 480, SDL_WINDOW_SHOWN),SDL_DestroyWindow);
	renderer_ = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED),SDL_DestroyRenderer);
}



void SdlHelper::close()
{
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

}

void SdlHelper::clearScreen()
{
	SDL_RenderClear(renderer_.get());
}
void SdlHelper::renderScreen()
{
	SDL_RenderPresent(renderer_.get());
}
void SdlHelper::setWindowSize(int width, int height)
{
	SDL_SetWindowSize(window_.get(), width, height);
}
void SdlHelper::setWindowTitle(const std::string & title)
{
	SDL_SetWindowTitle(window_.get(), title.c_str());
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

	SDL_RenderCopyEx(renderer_.get(), tex, NULL, &tmp, angle, nullptr, SDL_FLIP_NONE);

	SDL_SetTextureAlphaMod(tex, 255);  //After drawing we bring texture back to normal state ( not transparent ).
}

void SdlHelper::renderText(SDL_Rect* camera, TTF_Font* font, const std::string& message, int x, int y, const SDL_Color & color)
{

	SDL_Surface *surface = TTF_RenderText_Blended(font, message.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_.get(), surface);
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
	SDL_RenderCopy(renderer_.get(), filling, NULL, rectangle);
	SDL_SetTextureAlphaMod(filling, 0xff);  //After drawing we bring texture back to normal state ( not transparent ).
	SDL_SetRenderDrawColor(renderer_.get(), 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderDrawRect(renderer_.get(), rectangle);

	

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
	SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer_.get(), x1, y1, x2, y2);
}

void SdlHelper::drawPoint(SDL_Rect* camera, int x, int y, const SDL_Color & color)
{
	if (camera != nullptr)
	{
		x -= camera->x;
		y -= camera->y;
	}
	SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer_.get(), x, y);
}