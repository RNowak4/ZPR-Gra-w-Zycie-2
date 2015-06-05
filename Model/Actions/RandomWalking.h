/**
* @file RandomWalking.h
* @brief Virtual class that is used to represent
* @brief random walking.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_RANDOMWALKING_H_
#define MODEL_ACTIONS_RANDOMWALKING_H_

#include <ctime>
#include <random>
#include "CarnivoreAction.h"

class RandomWalking: public CarnivoreAction {
private:
	time_t lastChangeTime;

public:
	RandomWalking(Animal* animal_ptr);
	virtual ~RandomWalking();
	void performAction();
	virtual Action* chooseNextAction() = 0;
	void deleteAnimal(const Animal*);
	virtual string toString() = 0;
};

#endif /* MODEL_ACTIONS_RANDOMWALKING_H_ */
