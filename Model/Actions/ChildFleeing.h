/**
* @file ChildFleeing.h
* @brief Class that is used to represent
* @brief an chasing another animal action
* @brief which can be permorfm by carnivore animal.
*
* @author Radoslaw Nowak
*/
#ifndef MODEL_ACTIONS_CHILDFLEEING_H_
#define MODEL_ACTIONS_CHILDFLEEING_H_

#include "ChildAction.h"

class ChildFleeing: public ChildAction {
private:
	Animal* hunter;

public:
	ChildFleeing(Animal* animal_ptr, Animal* mother_ptr, Animal* hunter);
	virtual ~ChildFleeing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Fleeing";
	}
};

#endif /* MODEL_ACTIONS_CHILDFLEEING_H_ */
