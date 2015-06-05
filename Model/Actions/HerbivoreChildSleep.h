/**
* @file HerbivoreChildSleep.h
* @brief Class that is used to represent
* @brief sleeping permormed by herbivore children.
*
* @author Radoslaw Nowak
*/


#ifndef MODEL_HERBIVORECHILDSLEEP_H_
#define MODEL_HERBIVORECHILDSLEEP_H_

#include <string>

#include "ChildAction.h"

/**
@class HerbivoreChildSleep
Class that represents sleeping action being performed by herbivore child animal.
*/
class HerbivoreChildSleep: public ChildAction {
public:
	HerbivoreChildSleep(Animal* animal_ptr, Animal* mother_ptr);
	virtual ~HerbivoreChildSleep();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Sleeping";
	}
};

#endif /* MODEL_HERBIVORECHILDSLEEP_H_ */
