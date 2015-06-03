/**
 * @file Animal.h
 * @brief Class that represents an Animal
 *
 * @author Radoslaw Nowak
 */

#ifndef ANIMAL_H
#define	ANIMAL_H

#include <ctime>
#include <list>
#include <memory>
#include <string>

#include "Actions/Action.h"
#include "AnimalData.h"
#include "AnimalViewParameters.h"
#include "Attributes.h"
#include "Modifiers.h"
#include "States/State.h"
#include "ViewStructs.h"

class Action;
class TestAction;

typedef shared_ptr<Action> ActionPtr;
typedef shared_ptr<AnimalData> AnimalDataPtr;
typedef shared_ptr<State> StatePtr;

class Animal {
private:
	list<Animal*> childrenList;
	Modifiers animalModifiers;
	list<StatePtr> statesVector;
	Sex sex_;
	AnimalViewParameters animalViewParameters;
	Coordinates coordinates_;
	double velocity;
	double acceleration;
	double angleVelocity;
	int bornDate;

protected:
	ActionPtr currentAction;
	LocationData locationData_;
	Attributes actualAttributes_;
	double eatNeed_;
	double sleepNeed_;

public:
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
	virtual void updateStatus() = 0;

	/**
	 *@function returnCoodtinates
	 *@brief 	gets coordinates of an animal.
	 *@return 	animal's coordinates
	 */
	Coordinates returnCoodtinates() const {
		return locationData_.coordinates_;
	}

	/**
	 *@function returnLocationData
	 *@brief	gets current location data of an animal.
	 *@return	current location data of an animal
	 */
	LocationData* returnLocationData() {
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
	bool hasState(const string& stateName);

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

	void setAction(ActionPtr actionPtr) {
		currentAction = actionPtr;
	}

	/**
	 *@function doMove
	 *@brief 	Moves an animal
	 */
	void doMove();

	/**
	 *@function turnRight
	 *@brief 	Turns an animal right
	 */
	void turnRight() {
		angleVelocity = 1.0;
	}

	/**
	 *@function turnLeft
	 *@brief 	Turns an animal left
	 */
	void turnLeft() {
		angleVelocity = -1.0;
	}

	/**
	 *@function stopTurning
	 *@brief 	Stops animal's turning
	 */
	void stopTurning() {
		angleVelocity = 0.0;
	}

	/**
	 *@function isHerbivore
	 *@brief 	Function returns true, if an animal is herbivore
	 *@return	bool value
	 */
	bool isHerbivore() {
		return locationData_.animalType_ == HERBIVORE
				|| locationData_.animalType_ == HERBIVORE_CHILD;
	}

	/**
	 *@function setLookingAngle
	 *@brief 	Sets looking angle of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setLookingAngle(unsigned valueToSet) {
		locationData_.lookingAngle = valueToSet;
	}

	/**
	 *@function setVelocity
	 *@brief 	Sets velocity of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setVelocity(double valueToSet) {
		velocity = valueToSet;
	}

	/**
	 *@function setAcceleration
	 *@brief 	Sets acceleration of an animal
	 *@argument velutToSet	- value which will be set
	 */
	void setAcceleration(double valueToSet) {
		acceleration = valueToSet;
	}

	/**
	 *@function shouldDie
	 *@brief 	Returns this if animal should die or nullptr.
	 *@return	Pointer to animal class
	 */
	Animal* shouldDie();

	/**
	 *@function isMother
	 *@brief 	Returns true if an animal is mother
	 *@return	boolean value
	 */
	bool isMother() {
		return this->hasState("Mother");
	}

	/**
	 *@function getAttributes
	 *@brief 	returns actual attribues of an animal
	 *@return	reference to the structure
	 */
	Attributes& getAttributes() {
		return actualAttributes_;
	}

	double& returnEatNeed() {
		return eatNeed_;
	}

	double& returnSleepNeed() {
		return sleepNeed_;
	}
};

#endif	/* ANIMAL_H */
