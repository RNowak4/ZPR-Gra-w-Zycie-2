/**
* @file Fleeing.h
* @brief Class that is used to represent
* @brief fleeing children by herbivore.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_FLEEING_H_
#define MODEL_ACTIONS_FLEEING_H_

#include "Action.h"

/**
@class Fleeing
Class that represents fleeing action being performed by herbivore animal.
*/
class Fleeing: public Action {
private:
	Animal* hunter;

public:
	Fleeing(Animal* animal_ptr, Animal* hunter_);
	virtual ~Fleeing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Fleeing";
	}
};

#endif /* MODEL_ACTIONS_FLEEING_H_ */
