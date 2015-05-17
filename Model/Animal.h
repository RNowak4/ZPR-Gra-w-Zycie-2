/* 
 * File:   Animal.h
 * Author: Radek
 *
 * Created on 9 marca 2015, 21:29
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <vector>
#include <memory>
#include "Attributes.h"
#include "AnimalViewParameters.h"
#include "AnimalData.h"
#include "States/State.h"
#include "Actions/Action.h"

class AnimalViewParameters;
class Attributes;

class Animal {
private:
	unsigned width_, height_;
	Action* currentAction;
	Action* nextAction;

public:
	enum Sex {
		FEMALE, MALE
	};

protected:
	Modifiers animalModifiers;
	Attributes actualAttributes_;
	vector<State*> statesVector;

	Sex sex_;
	AnimalViewParameters animalViewParameters;
	Coordinates coordinates_;
	LocationData locationData_;

public:
	// Tymczasowo, zeby nie wywalalo errorow
	Animal() :
			animalModifiers(), actualAttributes_(animalModifiers) {

	}
	Animal(const Animal& orig);
	Animal(unsigned, unsigned, AnimalType);
	Animal(unsigned, unsigned);

	virtual ~Animal() {
	}

	virtual void updateStatus() = 0;

	virtual void doMove() = 0;

	Coordinates returnCoodtinates() const {
		return coordinates_;
		//return animalViewParameters.returnCoordinates();
	}

	const LocationData* returnLocationData() {
		//return animalViewParameters.returnLocationData();
		return &locationData_;
	}

	virtual bool isDangerous() = 0;
	bool isThatMe(int, int);
	AnimalData* getAnimalData();
};

#endif	/* ANIMAL_H */
