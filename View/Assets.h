/**
*@file Assets.h
*@brief Class that holds all the media required by the program.
*
*@author Damian  Mazurkiewicz
*/

#ifndef ASSETS_H
#define ASSETS_H
class Assets
{
public:
	static Assets& getInstance()
	{
		static Assets instance;
		return instance;
	}

private:
	Assets();
	Assets(const Assets&);
	Assets& operator=(const Assets&);
	~Assets();
};



#endif //ASSETS_H