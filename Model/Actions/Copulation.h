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
	Copulation(Animal* animal_ptr, Animal* animal_to_follow);
	virtual ~Copulation();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Copulation";
	}
};

#endif /* MODEL_ACTIONS_COPULATION_H_ */
