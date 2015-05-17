#include "Assets.h"


void Assets::loadAssets(const SdlHelper& helper)
{
	textures_[GRASS] = std::shared_ptr<SDL_Texture>(loadTexture("Assets/grass.png", helper), SDL_DestroyTexture);
	textures_[CARNIVORE] = std::shared_ptr<SDL_Texture>(loadTexture("Assets/Carnivore.png", helper), SDL_DestroyTexture);
	textures_[FRAME_BACKGROUND] = std::shared_ptr<SDL_Texture>(loadTexture("Assets/frameBackground.png", helper), SDL_DestroyTexture);

	fonts_[DEFAULT_FONT] = std::shared_ptr<TTF_Font>(TTF_OpenFont("Assets/comicbd.ttf", 14), TTF_CloseFont);
	
}
void Assets::disposeAssets()
{
	fonts_.clear();
	textures_.clear();
}

Assets::Assets()
{

}
Assets::Assets(const Assets&)
{

}
Assets& Assets::operator=(const Assets&)
{
	return *this;
}
Assets::~Assets()
{

}

SDL_Texture* Assets::loadTexture(const std::string& name, const SdlHelper& helper )
{
	SDL_Surface* tempSurface = IMG_Load(name.c_str());
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(helper.renderer_, tempSurface);
	SDL_FreeSurface(tempSurface);
	return newTexture;
}

std::shared_ptr<SDL_Texture> Assets::get(enum TextureID id)
{
	return textures_[id];
}

std::shared_ptr<TTF_Font> Assets::get(enum FontID id)
{
	return fonts_[id];
}