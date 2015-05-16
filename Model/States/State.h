/*
 * State.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef STATE_H_
#define STATE_H_

#include <string>
#include "../Attributes.h"

using namespace std;

class State {
private:
	Attributes attributes_;

public:
	State();
	virtual string toString() = 0;
};

#endif /* STATE_H_ */
