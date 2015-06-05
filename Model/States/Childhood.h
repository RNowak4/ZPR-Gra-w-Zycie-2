/**
* @file Model.h
* @brief Class that represents Childhood State.
* @brief This state is set to every child
* @brief and decreases animal's important attributes.
*
* @author Radoslaw Nowak
*/
#ifndef CHILDHOOD_H_
#define CHILDHOOD_H_

#include <string>

#include "State.h"

/**
@class Childhood
Class that represents state called Childhood.
*/
class Childhood: public State {
private:
	Animal* mother;
	double dec_values[3];

public:
	Childhood(Animal* animal_ptr, Animal* mother_ptr);
	virtual ~Childhood();
	string toString();
	bool isThatMe(string state_name);
	virtual void deleteAnimal(Animal* animal_ptr) {
		if (mother == animal_ptr) {
			mother = nullptr;
		}
	}
};

#endif /* CHILDHOOD_H_ */
