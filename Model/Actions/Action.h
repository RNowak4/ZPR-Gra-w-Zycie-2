/*
 * Action.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <memory>

class Model;

class Animal;

using namespace std;

class Action {
protected:
	Animal* animalPtr;
	Model* modelPtr;
	static Model* defaultModelPtr;

public:
	Action(Animal* animalPtr_);
	Action(Animal* animalPtr_, Model* modelPtr_) :
			animalPtr(animalPtr_), modelPtr(modelPtr_) {

	}
	virtual ~Action();
	virtual void performAction() = 0;
	virtual Action* chooseNextAction() = 0;
	virtual void deleteAnimal(const Animal*) = 0;
	static void setDefaultModel(Model* modelPtr) {
		defaultModelPtr = modelPtr;
	}
};

#endif /* ACTION_H_ */
