/**
 * @file Model.h
 * @brief Class that represents Mother State.
 * @brief This state is set to mother while she
 * @brief has young child.
 *
 * @author Radoslaw Nowak
 */

#ifndef MODEL_STATES_MOTHER_H_
#define MODEL_STATES_MOTHER_H_

#include <list>
#include <string>

#include "../Animal.h"
#include "State.h"

class Mother: public State {
public:
	Mother(Animal* animal_ptr);
	virtual ~Mother();
	virtual string toString();
	virtual bool isThatMe(string state_name);
	virtual void deleteAnimal(Animal* animal_ptr) {
	}
};

#endif /* MODEL_STATES_MOTHER_H_ */
