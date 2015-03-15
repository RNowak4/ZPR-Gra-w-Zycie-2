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
	Model model; // Tego nie mog� bo Radek nie zdefiniowa� konstruktora (Pozdro) xD
        // Pozdro 600. Juz dziala
	Controller controller;
	View view;
	view.run();
	
	system("PAUSE");
	return 0;
}
