/*
 * Hunting.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_HUNTING_H_
#define MODEL_ACTIONS_HUNTING_H_

#include "Action.h"

class Hunting: public Action {
private:
	Animal* animalToFollowPtr;

public:
	Hunting(Animal*, Animal*);
	virtual ~Hunting();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_ACTIONS_HUNTING_H_ */
