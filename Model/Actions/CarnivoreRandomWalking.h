/*
 * CarnivoreRandomWalking.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_
#define MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_

#include "CarnivoreAction.h"

class CarnivoreRandomWalking: public CarnivoreAction {
public:
	CarnivoreRandomWalking(Animal* animalPtr_);
	virtual ~CarnivoreRandomWalking();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*) {
		//do nothing about that
	}
};

#endif /* MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_ */
