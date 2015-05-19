/**
 * @file Animal.h
 * @brief Class that represents an Animal
 *
 * @author Radoslaw Nowak
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <vector>
#include <memory>
#include <cmath>
#include "Attributes.h"
#include "AnimalViewParameters.h"
#include "AnimalData.h"
#include "States/State.h"
#include "Actions/Action.h"
#include "Constants.h"

typedef shared_ptr<Action> ActionPtr;
typedef shared_ptr<AnimalData> AnimalDataPtr;
typedef shared_ptr<State> StatePtr;

class Animal {
private:
	ActionPtr currentAction;
	ActionPtr nextAction;

public:
	enum Sex {
		FEMALE, MALE
	};

	struct Velocity {
		double VX, VY;
		Velocity() :
				VX(0.0), VY(0.0) {
		}
		Velocity(double VX_, double VY_) :
				VX(VX_), VY(VY_) {
		}
		double returnVelocityValue() {
			return sqrt(VX * VX + VY * VY);
		}
	};

protected:
	Modifiers animalModifiers;
	Attributes actualAttributes_;
	vector<StatePtr> statesVector;

	Sex sex_;
	AnimalViewParameters animalViewParameters;
	Coordinates coordinates_;
	LocationData locationData_;
	Velocity velocity_;

public:
	// TODO Tymczasowo, zeby nie wywalalo errorow
	Animal() :
			animalModifiers(), actualAttributes_(animalModifiers) {
	}

	/**
	 *@function Animal
	 *@brief 	Copy Constructor.
	 */
	Animal(const Animal& orig);

	/**
	 *@function Animal
	 *@brief 	Creates an new Animal with random Modifiers.
	 */
	Animal(unsigned, unsigned, AnimalType = HERBIVORE);

	/**
	 *@function Animal
	 *@brief 	Creates an new Animal.
	 */
	Animal(unsigned, unsigned, const Modifiers&, AnimalType = HERBIVORE);

	/**
	 *@function ~Animal
	 *@brief 	destructor.
	 */
	virtual ~Animal() {
	}

	/**
	 *@function updateStatus
	 *@brief 	Updates status of an animal.
	 */
	void updateStatus();

	/**
	 *@function returnCoodtinates
	 *@brief 	gets coordinates of an animal.
	 *@return 	animal's coordinates
	 */
	Coordinates returnCoodtinates() const {
		return coordinates_;
	}

	/**
	 *@function returnLocationData
	 *@brief	gets current location data of an animal.
	 *@return	current location data of an animal
	 */
	const LocationData* returnLocationData() {
		return &locationData_;
	}

	/**
	 *@function isDangerous
	 *@brief	checks if animal is Dangerous for another
	 *@param another 		- another animal
	 *@return	bool falue
	 */
	virtual bool isDangerous(Animal* another) = 0;

	/**
	 *@function isThatMe
	 *@brief	checks if an animal is at position.
	 *@param x 		- position in x axis
	 *@param y		- position in y axis
	 *@return	bool falue
	 */
	bool isThatMe(unsigned x, unsigned y);

	/**
	 *@function isThatMe
	 *@brief	checks if an animal is at state.
	 *@param stateName	- name of an state
	 *@return	bool falue
	 */
	bool hasState(string stateName);

	/**
	 *@function setPosition
	 *@brief 	moves an animal to indicated position.
	 *@param x 		- position in x axis
	 *@param y		- position in y axis
	 */
	void setPosition(unsigned x, unsigned y);

	/**
	 *@function setPosition
	 *@brief 	moves an animal to indicated position.
	 *@param coodrinates	- coordinates of new position
	 */
	void setPosition(Coordinates coodrinates);

	/**
	 *@function getSex
	 *@brief 	gets animal sex.
	 *@return	Sex falue
	 */
	Sex getSex() {
		return sex_;
	}

	/**
	 *@function getAnimalData
	 *@brief 	Gets Data of an animal.
	 *@return	Pointer to AnimalData class
	 */
	AnimalData* getAnimalData();
};

#endif	/* ANIMAL_H */
