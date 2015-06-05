/**
* @file CarnivoreAction.h
* @brief Virtual class that is used to represent
* @brief an carnivore action which permorm an animal.
*
* @author Radoslaw Nowak
*/

#ifndef CARNIVOREACTION_H_
#define CARNIVOREACTION_H_

#include "Action.h"

/**
@class CarnivoreAction
Virtual class that represents action which can be performed by Carnivore animal.
*/
class CarnivoreAction: public Action {
public:
	CarnivoreAction(Animal* animal_ptr);
	virtual ~CarnivoreAction();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*)=0;
	virtual string toString() = 0;
};

#endif /* CARNIVOREACTION_H_ */
