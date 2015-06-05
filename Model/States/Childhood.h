/*
 * Childhood.h
 *
 *  Created on: 17-05-2015
 *      Author: radek
 */

#ifndef CHILDHOOD_H_
#define CHILDHOOD_H_

#include <string>

#include "State.h"

class Childhood: public State {
private:
	Animal* mother;
	double dec_values[3];

public:
	Childhood(Animal* animal_ptr, Animal* mother_ptr);
	virtual ~Childhood();
	string toString();
	bool isThatMe(string state_name);
};

#endif /* CHILDHOOD_H_ */
