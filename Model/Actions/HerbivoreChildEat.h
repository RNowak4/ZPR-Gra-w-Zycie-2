/*
 * HerbivoreChildEat.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_HERBIVORECHILDEAT_H_
#define MODEL_ACTIONS_HERBIVORECHILDEAT_H_

#include "ChildAction.h"

class HerbivoreChildEat: public ChildAction {
public:
	HerbivoreChildEat(Animal* animal_ptr, Animal* mother_ptr);
	virtual ~HerbivoreChildEat();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Eating";
	}
};

#endif /* MODEL_ACTIONS_HERBIVORECHILDEAT_H_ */
