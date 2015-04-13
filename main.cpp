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
	
	return 0;
}
