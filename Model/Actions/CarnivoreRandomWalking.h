/*
 * CarnivoreRandomWalking.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_
#define MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_

#include <random>
#include "CarnivoreAction.h"

using namespace std;

class CarnivoreRandomWalking: public CarnivoreAction {
private:
	time_t lastChangeTime;
	std::uniform_int_distribution<int> distribution1;
	std::uniform_int_distribution<int> distribution2;

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
