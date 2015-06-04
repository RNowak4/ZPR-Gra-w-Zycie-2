/*
 * LookingForPartner.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_LOOKINGFORPARTNER_H_
#define MODEL_ACTIONS_LOOKINGFORPARTNER_H_

#include "RandomWalking.h"

using namespace std;

class LookingForPartner: public RandomWalking {
public:
	LookingForPartner(Animal* animalPtr_);
	virtual ~LookingForPartner();
	Action* chooseNextAction();
	string toString() {
		return "Looking for patner";
	}
};

#endif /* MODEL_ACTIONS_LOOKINGFORPARTNER_H_ */
