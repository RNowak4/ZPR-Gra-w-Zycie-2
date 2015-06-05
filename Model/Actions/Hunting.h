/**
* @file Hunting.h
* @brief Class that is used to represent
* @brief hunting action permormed by carnivores.
*
* @author Radoslaw Nowak
*/

#ifndef MODEL_ACTIONS_HUNTING_H_
#define MODEL_ACTIONS_HUNTING_H_

#include <ctime>
#include <random>
#include "CarnivoreAction.h"

using namespace std;

/**
@class Hunting
Class that represents hunting action being performed by carnivore animal.
*/
class Hunting: public CarnivoreAction {
private:
	time_t lastChangeTime;
	std::uniform_int_distribution<int> distribution1;
	std::uniform_int_distribution<int> distribution2;

public:
	Hunting(Animal* animal_ptr);
	virtual ~Hunting();
	void performAction();
	Action* chooseNextAction();
	void deleteAnimal(const Animal*);
	string toString() {
		return "Hunting";
	}
};

#endif /* MODEL_ACTIONS_HUNTING_H_ */
