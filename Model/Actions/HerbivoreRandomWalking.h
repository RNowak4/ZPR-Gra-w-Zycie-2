/*
 * HerbivoreRandomWalking.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_HERBIVORERANDOMWALKING_H_
#define MODEL_ACTIONS_HERBIVORERANDOMWALKING_H_

#include "RandomWalking.h"

class HerbivoreRandomWalking: public RandomWalking {
public:
	HerbivoreRandomWalking(Animal* animalPtr_);
	virtual ~HerbivoreRandomWalking();
	virtual Action* chooseNextAction();
};

#endif /* MODEL_ACTIONS_HERBIVORERANDOMWALKING_H_ */
