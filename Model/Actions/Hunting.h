/*
 * Hunting.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_HUNTING_H_
#define MODEL_ACTIONS_HUNTING_H_

#include <ctime>
#include <random>
#include "Action.h"

using namespace std;

class Hunting: public Action {
private:
	time_t lastChangeTime;
	std::uniform_int_distribution<int> distribution1;
	std::uniform_int_distribution<int> distribution2;

public:
	Hunting(Animal*);
	virtual ~Hunting();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Hunting";
	}
};

#endif /* MODEL_ACTIONS_HUNTING_H_ */
