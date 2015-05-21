#ifndef GAME_OF_LIFE_EXCEPTION
#define GAME_OF_LIFE_EXCEPTION

#include <exception>

class GameOfLifeException : public std::exception
{
};

class LoadingAssetsException : public GameOfLifeException
{
};

class LoadingSettingsExcepion : public GameOfLifeException
{
};

#endif //GAME_OF_LIFE_EXCEPTION