/**
*@file View.cpp
* POZDROWIENIA DLA RADKA
*@author Damian Mazurkiewicz
*/
#include "View.h"
#include  "../Model/Model.h"
#include "../Controller/Controller.h"
#include <sstream>
View::View() : mySDL_(), controller_(nullptr), event_(), quit_(false)
{
	camera_.x = 0; 
	camera_.y = 0; 
	camera_.w = SCREEN_WIDTH; 
	camera_.h = SCREEN_HEIGHT;
}

void View::drawCreature(const LocationData& data)
{
	mySDL_.draw(&camera_, Assets::getInstance().get(Assets::CARNIVORE).get(), data.coordinates_.x, data.coordinates_.y, true, data.lookingAngle, 150);
}

void View::getController(Controller* controller)
{
	controller_ = controller;
}

/**
*This method will be drawing specific information about creature and its vision range on the screen.
*/
void View::drawCreatureInfo(int x, int y, const AnimalData* data)
{
	int fontHeight = 25;
	int margin = 10;
	std::shared_ptr<TTF_Font> font = Assets::getInstance().get(Assets::DEFAULT_FONT);

	auto vec1 = &data->returnPairVector();
	auto vec2 = &data->returnStringVector();
	SDL_Rect frame; frame.x = x; frame.y = y; frame.w = 200; frame.h = 2 * margin + (vec1->size() + vec2->size())*fontHeight;
	mySDL_.drawFrame(&camera_, &frame, Assets::getInstance().get(Assets::FRAME_BACKGROUND).get());
	SDL_Color col; col.a = col.b = col.g = col.r = 0x00;
	
	int c = 0;
	std::stringstream ss;
	
	for (auto i = vec1->begin(); i != vec1->end(); ++i,++c)
	{
		ss <<(*i).first << " " << (*i).second;
		mySDL_.renderText(&camera_, font.get(), ss.str(), x + margin, y + margin + c*fontHeight, col);
		ss.str("");
	}
	for (auto i = vec2->begin(); i != vec2->end(); ++i)
	{
		mySDL_.renderText(&camera_, font.get(), (*i), x + margin, y + margin + c*fontHeight, col);
		c++;
	}
}

/**
* Method for drawing grass relative to camera position.
*/
void View::drawBackground()
{
	int backgrWidth; int backgrHeight;
	shared_ptr<SDL_Texture> tex = Assets::getInstance().get(Assets::GRASS);

	SDL_QueryTexture(tex.get(), nullptr, nullptr, &backgrWidth, &backgrHeight);

	int xOffset = - (camera_.x%backgrWidth);
	int yOffset = -(camera_.y%backgrHeight);

	for (int i = xOffset; i < camera_.w; i += backgrWidth)
	{
		for (int j = yOffset; j < camera_.h; j += backgrHeight)
		{
			mySDL_.draw(nullptr, tex.get(), i, j);
		}
	}
}

void View::run()
{
	
	mySDL_.init();	///Initialize new SDL Screen with renderer
	mySDL_.setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	mySDL_.setWindowTitle("Game of life.");

	Assets::getInstance().loadAssets(mySDL_); ///Loading all neccesary files.

	using namespace std::chrono;
	
	//Time points for time measuring
	high_resolution_clock::time_point second = high_resolution_clock::now();
	high_resolution_clock::time_point frame = high_resolution_clock::now();
	duration<double> time_span;

	int fpsCounter = 0;

	quit_ = false;

	
	//Main loop of program
	while (!quit_)
	{
		//Measuring time of new frame. 
		frame = high_resolution_clock::now();
		mySDL_.clearScreen(); //Clear screen.

		//Sending input from user to conroller to handle it.
		while (SDL_PollEvent(&event_) != 0)
		{
			controller_->handleEvent(&event_);
		}

		drawBackground();

		//FPS counter only for testing purposes!
		++fpsCounter;
		time_span = duration_cast<duration<double>>(high_resolution_clock::now() - second);
		if (time_span.count() >= 1)
		{
			std::cout << fpsCounter << " FPS" <<std::endl;
			fpsCounter = 0;
			second = high_resolution_clock::now();
		}


		controller_->update();
		
		mySDL_.renderScreen(); // Render screen.

		//We keep the frames per second at relatively fixed amount. 
		time_span = duration_cast<duration<double>>(high_resolution_clock::now() - frame);
		if (time_span.count()< FRAME_TIME)
			SDL_Delay((FRAME_TIME - time_span.count()) * 1000);
	}

	Assets::getInstance().disposeAssets(); ///Disposing  all loaded files.
	mySDL_.close();
}

void View::quit()
{
	quit_ = true;
}

void View::moveCamera(int x, int y)
{
	camera_.x += x;
	camera_.y += y;

}

const SDL_Rect & View::getCamera()
{
	return camera_;
}
