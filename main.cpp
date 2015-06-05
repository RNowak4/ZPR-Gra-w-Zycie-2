#include "Model/Model.h"
#include "Controller/Controller.h"
#include "View/View.h"
#include "View/Graphics.h"
#include "Exception/GameOfLifeException.h"
#include <iostream>

int main(int argc, char** argv) {
	
	try{

		Model model;
		View view;
		Controller controller(&model,&view);

		view.run(&controller);
	}
	catch (InitializingSdlSystemsException& e)
	{
		Graphics::unloadLibraries();
		std::cerr << e.what() << std::endl;
	}
	catch (LoadingMediaException& e)
	{
		Graphics::unloadLibraries();
		std::cerr << e.what() << std::endl;
	}
	catch (LoadingSettingsExcepion& e)
	{
		std::cerr << e.what()<< std::endl;
	}

	
	#ifdef _WIN32
	system("PAUSE");
	#endif
	
	return 0;
}
