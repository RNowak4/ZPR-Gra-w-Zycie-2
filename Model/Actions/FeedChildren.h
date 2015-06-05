/**
* @file FeedChildren.h
* @brief Class that is used to represent
* @brief feeding children by their mother.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_FEEDCHILDREN_H_
#define MODEL_ACTIONS_FEEDCHILDREN_H_

#include <list>

#include "../Animal.h"
#include "CarnivoreAction.h"

/**
@class FeedChildren
Class that represents feeding childre action being performed by carnivore animal.
*/
class FeedChildren: public CarnivoreAction {
private:
	list<Animal*> childrenList;
	Animal* currentChild;

public:
	FeedChildren(Animal* animal_ptr);
	virtual ~FeedChildren();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Feeding children";
	}
};

#endif /* MODEL_ACTIONS_FEEDCHILDREN_H_ */
