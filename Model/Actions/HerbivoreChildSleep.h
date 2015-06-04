/*
 * HerbivoreChildSleep.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_HERBIVORECHILDSLEEP_H_
#define MODEL_HERBIVORECHILDSLEEP_H_

#include <string>

#include "ChildAction.h"

class HerbivoreChildSleep: public ChildAction {
public:
	HerbivoreChildSleep(Animal* animalPtr_, Animal* motherPtr_);
	virtual ~HerbivoreChildSleep();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Sleeping";
	}
};

#endif /* MODEL_HERBIVORECHILDSLEEP_H_ */
