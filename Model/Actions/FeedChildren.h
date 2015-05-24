/*
 * FeedChildren.h
 *
 *  Created on: 24 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_FEEDCHILDREN_H_
#define MODEL_ACTIONS_FEEDCHILDREN_H_

#include <list>

#include "../Animal.h"
#include "Action.h"

class FeedChildren: public Action {
private:
	list<Animal*> childrenList;
	Animal* currentChild;

public:
	FeedChildren(Animal* animalPtr_);
	virtual ~FeedChildren();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_ACTIONS_FEEDCHILDREN_H_ */
