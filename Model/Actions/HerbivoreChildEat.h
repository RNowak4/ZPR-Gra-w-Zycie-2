/**
* @file HerbivoreChildEat.h
* @brief Class that is used to represent
* @brief eating permormed by herbivore children.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_HERBIVORECHILDEAT_H_
#define MODEL_ACTIONS_HERBIVORECHILDEAT_H_

#include "ChildAction.h"

/**
@class HerbivoreChildEat
Class that represents eating action being performed by herbivore child animal.
*/
class HerbivoreChildEat: public ChildAction {
public:
	HerbivoreChildEat(Animal* animal_ptr, Animal* mother_ptr);
	virtual ~HerbivoreChildEat();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Eating";
	}
};

#endif /* MODEL_ACTIONS_HERBIVORECHILDEAT_H_ */
