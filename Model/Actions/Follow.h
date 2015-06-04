/*
 * Follow.h
 *
 *  Created on: 22 maj 2015
 *      Author: radek
 */

#ifndef MODEL_ACTIONS_FOLLOW_H_
#define MODEL_ACTIONS_FOLLOW_H_

#include "Action.h"

struct Coordinates;

class Follow: public Action {
private:
	Animal* animalToFollowPtr;

public:
	Follow(Animal*, Animal*);
	virtual ~Follow();
	virtual void performAction();
	virtual Action* chooseNextAction();
	virtual void deleteAnimal(const Animal*);
	string toString() {
		return "Following";
	}
};

#endif /* MODEL_ACTIONS_FOLLOW_H_ */
