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
	virtual Action* chooseNextAction() = 0;
	void deleteAnimal(const Animal*);
	virtual string toString() = 0;
};

#endif /* MODEL_ACTIONS_RANDOMWALKING_H_ */
