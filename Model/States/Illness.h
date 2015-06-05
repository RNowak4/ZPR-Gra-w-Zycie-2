/**
 * @file Model.h
 * @brief Class that represents Illness State.
 * @brief This state is set randomly to an animal
 * @brief and decreases some of it's attributes.
 *
 * @author Radoslaw Nowak
 */

#ifndef ILLNESS_H_
#define ILLNESS_H_

#include <string>

#include "State.h"

/**
@class Mother
Class that represents illness.
*/
class Illness: public State {
public:
	Illness(Animal* animal_ptr);
	~Illness();
	string toString();
	bool isThatMe(string state_name) {
		if (state_name == "Illness")
			return true;
		return false;
	}
	virtual void deleteAnimal(Animal* animal_ptr) {
	}
};

#endif /* ILLNESS_H_ */
