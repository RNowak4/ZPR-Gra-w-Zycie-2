#include "Model/Model.h"
#include "Controller/Controller.h"
#include "View/View.h"

/* Do implementacji w Controllerze:
 * 
 */

/* Do implementacji w Modelu:
 * 
 */

int main(int argc, char** argv) {
	
	Model model; 
	Controller controller;
	View view;

	view.getController(&controller);
	controller.getView(&view);
	controller.getModel(&model);

	view.run();
	#ifdef _WIN32
	system("PAUSE");
	#endif
	
	return 0;
}
