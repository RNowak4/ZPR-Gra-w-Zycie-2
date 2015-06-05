/**
* @file HerbivoreRandomWalking.h
* @brief Class that is used to represent
* @brief random walking  permormed by herbivores.
*
* @author Radoslaw Nowak
*/


#ifndef MODEL_ACTIONS_HERBIVORERANDOMWALKING_H_
#define MODEL_ACTIONS_HERBIVORERANDOMWALKING_H_

#include "RandomWalking.h"

class HerbivoreRandomWalking: public RandomWalking {
public:
	HerbivoreRandomWalking(Animal* animal_ptr);
	virtual ~HerbivoreRandomWalking();
	virtual Action* chooseNextAction();
	string toString() {
		return "Random walking";
	}
};

#endif /* MODEL_ACTIONS_HERBIVORERANDOMWALKING_H_ */
