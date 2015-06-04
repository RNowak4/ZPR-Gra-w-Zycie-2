/*
 * HerbivoreChildSleep.h
 *
 *  Created on: 4 cze 2015
 *      Author: radek
 */

#ifndef MODEL_HERBIVORECHILDSLEEP_H_
#define MODEL_HERBIVORECHILDSLEEP_H_

#include "Actions/ChildAction.h"

class HerbivoreChildSleep: public ChildAction {
public:
	HerbivoreChildSleep(Animal* animalPtr_, Animal* motherPtr_);
	virtual ~HerbivoreChildSleep();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
};

#endif /* MODEL_HERBIVORECHILDSLEEP_H_ */
