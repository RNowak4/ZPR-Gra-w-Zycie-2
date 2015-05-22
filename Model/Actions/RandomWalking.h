/*
 * RandomWalking.h
 *
 *  Created on: 21 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_RANDOMWALKING_H_
#define MODEL_ACTIONS_RANDOMWALKING_H_

#include "CarnivoreAction.h"

class RandomWalking: public CarnivoreAction {
public:
	RandomWalking(Animal* animalPtr_);
	virtual ~RandomWalking();
	void performAction();
	Action* chooseNextAction();
};

#endif /* MODEL_ACTIONS_RANDOMWALKING_H_ */
