/**
* @file Chasing.h
* @brief Class that is used to represent
* @brief an chasing another animal action 
* @brief which can be permorfm by carnivore animal.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_CHASING_H_
#define MODEL_ACTIONS_CHASING_H_

#include "Action.h"

/**
@class Chasing
Class that represents chasing action being performed by carnivore animal.
*/
class Chasing: public Action {
private:
	Animal* animalToFollowPtr;

public:
	/**
	*@function Chasing
	*@brief 	An only constructor of Chasing class
	*@argument animal_ptr -	current animal's pointer.
	*@argument animal_to_follow_ptr - pointer to an animal which current animal will chase
	*/
	Chasing(Animal* animal_ptr, Animal* animal_to_follow_ptr);
	virtual ~Chasing();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Chasing";
	}
};

#endif /* MODEL_ACTIONS_CHASING_H_ */
