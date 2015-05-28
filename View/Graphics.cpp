#include "Graphics.h"
#include "../Exception/GameOfLifeException.h"
#include <iostream>

Graphics::Graphics()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 || IMG_Init(IMG_INIT_PNG) == 0 || TTF_Init() != 0)
	{
		throw InitializingGraphicsException();
	}
	//TODO Exception throwing!
	window_ = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Game of Life", 30, 30, 640, 480, SDL_WINDOW_SHOWN), [](SDL_Window* w){SDL_DestroyWindow(w); std::cout << "w"; });
	renderer_ = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);

	textures_[GRASS] = loadTexture("Assets/grass.png"), SDL_DestroyTexture;
	textures_[CARNIVORE] = loadTexture("Assets/carnivore.png"), SDL_DestroyTexture;
	textures_[HERBIVORE] = loadTexture("Assets/herbivore.png"), SDL_DestroyTexture;
	textures_[FRAME_BACKGROUND] = loadTexture("Assets/frameBackground.png"), SDL_DestroyTexture;

	fonts_[DEFAULT_FONT] = std::shared_ptr<TTF_Font>(TTF_OpenFont("Assets/verdanab.ttf", 12), TTF_CloseFont);

	for (auto i : textures_)
	{
		if (!i.second)
		{
			throw LoadingAssetsException();
		}
	}
}

Graphics& Graphics::getInstance()
{
	static Graphics graphics;
	return graphics;
}

void Graphics::dispose(Graphics& graphics)
{
	graphics.textures_.clear();
	graphics.fonts_.clear();
	graphics.renderer_.reset();
	graphics.window_.reset();

	IMG_Quit();
	SDL_Quit();
	TTF_Quit();
}
Graphics::~Graphics()
{
	dispose(*this);
}
std::shared_ptr<SDL_Texture> Graphics::loadTexture(const std::string& path)
{
	std::shared_ptr<SDL_Surface> tempSurface(IMG_Load(path.c_str()),SDL_FreeSurface);
	std::shared_ptr<SDL_Texture> newTexture(SDL_CreateTextureFromSurface(renderer_.get(), tempSurface.get()), SDL_DestroyTexture);
	return newTexture;
}

std::shared_ptr<SDL_Texture> Graphics::get(enum TextureID id)
{
	return textures_[id];
}
std::shared_ptr<TTF_Font> Graphics::get(enum FontID id)
{
	return fonts_[id];
}

void Graphics::clearScreen()
{
	SDL_RenderClear(renderer_.get());
}
void Graphics::renderScreen()
{
	SDL_RenderPresent(renderer_.get());
}
void Graphics::setWindowSize(int width, int height)
{
	SDL_SetWindowSize(window_.get(), width, height);
}
void Graphics::setWindowTitle(const std::string & title)
{
	SDL_SetWindowTitle(window_.get(), title.c_str());
}

void Graphics::draw(const SDL_Rect& camera, std::shared_ptr<SDL_Texture> tex, int x, int y, bool centered, double angle, Uint8 alpha)
{
	SDL_Rect tmp{ x, y };
	SDL_QueryTexture(tex.get(), nullptr, nullptr, &tmp.w, &tmp.h); //How big is the image to draw.

	if (centered == true)
	{
		tmp.x -= tmp.w / 2;
		tmp.y -= tmp.h / 2;
	}

	/*Check if object is within camera bounds.*/
	if (!overlap(tmp, camera))
	{
		return;
	}
	tmp.x -= camera.x;
	tmp.y -= camera.y;

	SDL_SetTextureAlphaMod(tex.get(), alpha); //Setting alpha for texture.
	SDL_RenderCopyEx(renderer_.get(), tex.get(), NULL, &tmp, angle, nullptr, SDL_FLIP_NONE);
	SDL_SetTextureAlphaMod(tex.get(), 255);  //After drawing we bring texture back to normal state ( not transparent ).
}

void Graphics::renderText(const SDL_Rect& camera, std::shared_ptr<TTF_Font> font, const std::string& message, int x, int y, const SDL_Color& color)
{
	std::shared_ptr<SDL_Surface>  surface(TTF_RenderText_Blended(font.get(), message.c_str(), color), SDL_FreeSurface);
	std::shared_ptr<SDL_Texture>  texture(SDL_CreateTextureFromSurface(renderer_.get(), surface.get()), SDL_DestroyTexture);
	draw(camera, texture, x, y);
}

void Graphics::drawFrame(const SDL_Rect& camera, SDL_Rect rectangle, std::shared_ptr<SDL_Texture> filling)
{
	/*Check if object is within camera bounds.*/
	if (!overlap(rectangle, camera))
	{
		return;
	}
	rectangle.x -= camera.x;
	rectangle.y -= camera.y;

	SDL_SetTextureAlphaMod(filling.get(), 0x80); //Setting alpha for texture.
	SDL_RenderCopy(renderer_.get(), filling.get(), nullptr, &rectangle);
	SDL_SetTextureAlphaMod(filling.get(), 0xff);  //After drawing we bring texture back to normal state ( not transparent ).
	SDL_SetRenderDrawColor(renderer_.get(), 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderDrawRect(renderer_.get(), &rectangle);



}

bool Graphics::overlap(const SDL_Rect& r1, const SDL_Rect& r2)
{
	if (r1.y >= r2.y + r2.h ||
		r1.y + r1.h <= r2.y ||
		r1.x + r1.w <= r2.x ||
		r1.x >= r2.x + r2.w)
	{
		return false;
	}
	return true;
}

void Graphics::drawLine(const SDL_Rect& camera, int x1, int y1, int x2, int y2, const SDL_Color & color)
{
	/*Check if line is within camera bounds.*/
	SDL_Rect area{ x1, y1, std::abs(x2 - x1), std::abs(y2 - y1) };
	if (!overlap(area, camera))
	{
		return;
	}
	x1 -= camera.x;
	x2 -= camera.x;
	y1 -= camera.y;
	y2 -= camera.y;

	SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer_.get(), x1, y1, x2, y2);
}

void Graphics::drawPoint(const SDL_Rect& camera, int x, int y, const SDL_Color & color)
{
	/*Check if point is within camera bounds.*/
	SDL_Rect area{ x, y, 1, 1 };
	if (!overlap(area, camera))
	{
		return;
	}
	x -= camera.x;
	y -= camera.y;

	SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer_.get(), x, y);
}