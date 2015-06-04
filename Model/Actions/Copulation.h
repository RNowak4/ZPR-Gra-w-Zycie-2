/*
 * Copulation.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_COPULATION_H_
#define MODEL_ACTIONS_COPULATION_H_

#include "Action.h"

class Copulation: public Action {
private:
	Animal* animalToFollowPtr;

public:
	Copulation(Animal* animalPtr_, Animal* animalToFollow);
	virtual ~Copulation();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_ACTIONS_COPULATION_H_ */
