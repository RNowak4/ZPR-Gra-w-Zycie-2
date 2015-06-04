/*
 * CarnivoreRandomWalking.h
 *
 *  Created on: 27 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_
#define MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_

#include <ctime>
#include <random>
#include "RandomWalking.h"

using namespace std;

class CarnivoreRandomWalking: public RandomWalking {
public:
	CarnivoreRandomWalking(Animal* animalPtr_);
	virtual ~CarnivoreRandomWalking();
	Action* chooseNextAction();
	string toString() {
		return "Random Walking";
	}
};

#endif /* MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_ */
