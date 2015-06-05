/**
* @file HerbivoreAction.h
* @brief Virtual classthat is used to represent
* @brief an action performed by herbivore animals.
*
* @author Radoslaw Nowak
*/

#ifndef HERBIVOREACTION_H_
#define HERBIVOREACTION_H_

#include "Action.h"

/**
@class HerbivoreAction
Virtual class that represents an action being performed by herbivore animal.
*/
class HerbivoreAction: public Action {
public:
	HerbivoreAction(Animal* animal_ptr);
	virtual ~HerbivoreAction();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*) = 0;
	virtual string toString() = 0;
};

#endif /* HERBIVOREACTION_H_ */
