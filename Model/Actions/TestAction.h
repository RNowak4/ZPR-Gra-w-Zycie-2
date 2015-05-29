/*
 * TestAction.h
 *
 *  Created on: 19 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_TESTACTION_H_
#define MODEL_ACTIONS_TESTACTION_H_

#include <ctime>
#include <random>

#include "Action.h"

class TestAction: public Action {
private:
	time_t lastChangeTime;
	std::uniform_int_distribution<int> distribution1;
	std::uniform_int_distribution<int> distribution2;

public:
	TestAction(Animal*);
	TestAction(Animal*, Model*);
	virtual ~TestAction();
	void deleteAnimal(const Animal*) {
		//do nothing about that
	}
	void performAction();
	Action*chooseNextAction();
};

#endif /* MODEL_ACTIONS_TESTACTION_H_ */
