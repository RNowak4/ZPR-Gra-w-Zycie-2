/*
 * Chasing.h
 *
 *  Created on: 3 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CHASING_H_
#define MODEL_ACTIONS_CHASING_H_

#include "Action.h"

class Chasing: public Action {
private:
	Animal* animalToFollowPtr;

public:
	Chasing(Animal*, Animal*);
	virtual ~Chasing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_ACTIONS_CHASING_H_ */
