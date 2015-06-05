/**
* @file CarnivoreSleeping.h
* @brief Class that is used to represent
* @brief an sleep action which can be permorfm by carnivore animal.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_CARNIVORESLEEPING_H_
#define MODEL_ACTIONS_CARNIVORESLEEPING_H_

#include "CarnivoreAction.h"

/**
@class CarnivoreSleeping
Class that represents sleeping action being performed by carnivore animal.
*/
class CarnivoreSleeping: public CarnivoreAction {
private:
	static const unsigned decreaseValue = 200;

public:
	CarnivoreSleeping(Animal* animal_ptr);
	virtual ~CarnivoreSleeping();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Sleeping";
	}
};

#endif /* MODEL_ACTIONS_CARNIVORESLEEPING_H_ */
