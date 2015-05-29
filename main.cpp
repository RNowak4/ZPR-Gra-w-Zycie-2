#include "Model/Model.h"
#include "Controller/Controller.h"
#include "View/View.h"
#include "View/Graphics.h"
#include "Exception/GameOfLifeException.h"

/* Do implementacji w Controllerze:
 * 
 */

/* Do implementacji w Modelu:
 * 
 */

int main(int argc, char** argv) {
	
	try{
		Model model;
		Controller controller;
		View view;

		view.getController(&controller);
		controller.getView(&view);
		controller.getModel(&model);

		view.run();
	}
	catch (InitializingSdlSystemsException& e)
	{
		Graphics::unloadLibraries();
		std::cerr << "Unabled to initialize SDL systems." << std::endl;
	}
	catch (LoadingMediaException& e)
	{
		Graphics::unloadLibraries();
		std::cerr << "Unabled to load all files." << std::endl;
	}
	catch (LoadingSettingsExcepion& e)
	{
		std::cerr << "Incorrect settings.txt file." << std::endl;
	}

	
	#ifdef _WIN32
	system("PAUSE");
	#endif
	
	return 0;
}
