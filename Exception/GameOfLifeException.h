#ifndef GAME_OF_LIFE_EXCEPTION
#define GAME_OF_LIFE_EXCEPTION

#include <exception>

struct GameOfLifeException : public std::exception
{
};

struct InitializingSdlSystemsException : public GameOfLifeException
{
	virtual const char* what() const throw()
	{
		return "Unabled to initialize SDL systems.";
	}
};

struct InitalizingControllerException : public GameOfLifeException
{
	virtual const char* what() const throw()
	{
		return "Unabled to initialize Controller.";
	}
};

struct InitalizingViewException : public GameOfLifeException
{
	virtual const char* what() const throw()
	{
		return "Unabled to initialize View.";
	}
};

struct LoadingMediaException : public GameOfLifeException
{
	virtual const char* what() const throw()
	{
		return "Failed in all files.";
	}
};

struct LoadingSettingsExcepion : public GameOfLifeException
{
	virtual const char* what() const throw()
	{
		return "Incorrect settings.txt file.";
	}
};

struct CreatureConstructionException : public GameOfLifeException
{

};


#endif //GAME_OF_LIFE_EXCEPTION