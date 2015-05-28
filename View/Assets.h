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
#include <memory>

class Assets
{
public:
	enum TextureID
	{
		GRASS, HERBIVORE, CARNIVORE, FRAME_BACKGROUND
	};
	enum FontID
	{
		DEFAULT_FONT,
	};

	/**
	*Assets class is a singleton. It is because creating more objects of this class 
	*has no practical use and it can only waste memory.
	*/
	static Assets& getInstance()
	{
		static Assets instance;
		return instance;
	}

	/**
	*Load necessary files to memory.
	*@param 
	*/
	void loadAssets(const SdlHelper&  sdl);
	std::shared_ptr<SDL_Texture> get(enum TextureID id);
	std::shared_ptr<TTF_Font> get(enum FontID id);
	void disposeAssets();

private:
	Assets();
	Assets(const Assets&);
	Assets& operator=(const Assets&);
	~Assets();

	SDL_Texture* loadTexture(const std::string &, const SdlHelper&);

	std::map<enum TextureID, std::shared_ptr<SDL_Texture> > textures_;
	std::map<enum FontID, std::shared_ptr<TTF_Font> > fonts_;
};
#endif //ASSETS_H