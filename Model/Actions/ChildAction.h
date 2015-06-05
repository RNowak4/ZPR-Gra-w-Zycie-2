/**
* @file ChildAction.h
* @brief Virtual class that is used to represent
* @brief an sleep action which can be permorfm by carnivore animal.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_CHILDACTION_H_
#define MODEL_ACTIONS_CHILDACTION_H_

#include "Action.h"

/**
@class ChildAction
Virtual class that represents action which can perform only child.
*/
class ChildAction: public Action {
protected:
	Animal* motherPtr;

public:
	ChildAction(Animal* animal_ptr, Animal* mother_ptr);
	virtual ~ChildAction();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*) = 0;
	virtual string toString() = 0;
};

#endif /* MODEL_ACTIONS_CHILDACTION_H_ */
