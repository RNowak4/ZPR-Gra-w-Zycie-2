/*
 * State.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef STATE_H_
#define STATE_H_

#include <string>

class Animal;

using namespace std;

class State {
protected:
	Animal* animalPtr;

public:
	State();
	State(Animal*);
	virtual ~State() { }
	virtual string toString() = 0;
	virtual bool isThatMe(string state_name) = 0;
};

#endif /* STATE_H_ */
