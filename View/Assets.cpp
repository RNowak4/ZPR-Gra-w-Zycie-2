#include "Assets.h"

void Assets::loadAssets(const SdlHelper& helper)
{
	grass_ = loadTexture("Assets/grass.png",helper);
	carnivore_ = loadTexture("Assets/Carnivore.png",helper);
}
void Assets::disposeAssets()
{
	SDL_DestroyTexture(carnivore_);
	SDL_DestroyTexture(grass_);
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
	return newTexture;
}
