/*
 * HerbivoreAction.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef HERBIVOREACTION_H_
#define HERBIVOREACTION_H_

#include "Action.h"

class HerbivoreAction: public Action {
public:
	HerbivoreAction(Animal* animal_ptr);
	virtual ~HerbivoreAction();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*) = 0;
	virtual string toString() = 0;
};

#endif /* HERBIVOREACTION_H_ */
