/*
 * RandomWalking.h
 *
 *  Created on: 21 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_RANDOMWALKING_H_
#define MODEL_ACTIONS_RANDOMWALKING_H_

#include <ctime>
#include <random>
#include "CarnivoreAction.h"

class RandomWalking: public CarnivoreAction {
private:
	time_t lastChangeTime;
	std::uniform_int_distribution<int> distribution1;
	std::uniform_int_distribution<int> distribution2;

public:
	RandomWalking(Animal* animalPtr_);
	virtual ~RandomWalking();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*) {
		//do nothing about that
	}
};

#endif /* MODEL_ACTIONS_RANDOMWALKING_H_ */
