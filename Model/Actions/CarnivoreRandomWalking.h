/**
* @file CarnivoreRandomWalking.h
* @brief Class that is used to represent
* @brief an random walking carnivore 
* @brief action which permorm an animal.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_
#define MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_

#include <ctime>
#include <random>
#include "RandomWalking.h"

using namespace std;

/**
@class CarnivoreRandomWalking
Class that represents random walking action being performed by carnivore animal.
*/
class CarnivoreRandomWalking: public RandomWalking {
public:
	CarnivoreRandomWalking(Animal* animal_ptr);
	virtual ~CarnivoreRandomWalking();
	Action* chooseNextAction();
	string toString() {
		return "Random Walking";
	}
};

#endif /* MODEL_ACTIONS_CARNIVORERANDOMWALKING_H_ */
