/**
* @file Sleeping.h
* @brief Class that is used to represent
* @brief sleep action permormed by carnivores.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_SLEEPING_H_
#define MODEL_ACTIONS_SLEEPING_H_

#include "Action.h"

/**
@class Sleeping
Class that represents sleeping action being performed by carnivore animal.
*/
class Sleeping: public Action {
private:
	static const unsigned decreaseValue = 200;

public:
	Sleeping(Animal* animal_ptr);
	virtual ~Sleeping();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Sleeping";
	}
};

#endif /* MODEL_ACTIONS_SLEEPING_H_ */
