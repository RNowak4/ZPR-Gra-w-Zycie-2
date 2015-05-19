/*
 * Action.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <memory>

using namespace std;

class Animal;

typedef shared_ptr<Animal> AnimalPtr;

class Action {
private:
	const AnimalPtr animalPtr;

public:
	Action();
	Action(AnimalPtr animalPtr_) :
			animalPtr(animalPtr_) {

	}
	virtual ~Action();
	virtual void performAction() = 0;
	virtual shared_ptr<Action> chooseNextAction() = 0;
};

#endif /* ACTION_H_ */
