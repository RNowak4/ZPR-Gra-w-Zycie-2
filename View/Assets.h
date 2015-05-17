/**
*@file Assets.h
*@brief Class that holds all the media required by the program.
*
*@author Damian  Mazurkiewicz
*/

#ifndef ASSETS_H
#define ASSETS_H

#include "SdlHelper.h"
#include <map>

class Assets
{
public:
	enum TextureID
	{
		GRASS, HERBIVORE, CARNIVORE, FRAME_BACKGROUND
	};
	static Assets& getInstance()
	{
		static Assets instance;
		return instance;
	}

	void loadAssets(const SdlHelper&);
	void disposeAssets();

	//List of all necessary images and fonts
	SDL_Texture* grass_;
	SDL_Texture* herbivore_;
	SDL_Texture* carnivore_;
	SDL_Texture* frameBackground_;

//	std::map<std::string, std::shared_ptr<SDL_Texture>> textures_;

	TTF_Font* font_;

	
private:
	Assets();
	Assets(const Assets&);
	Assets& operator=(const Assets&);
	~Assets();

	SDL_Texture* loadTexture(const std::string &, const SdlHelper&);

	
	//TTF_Font* font_;
};



#endif //ASSETS_H